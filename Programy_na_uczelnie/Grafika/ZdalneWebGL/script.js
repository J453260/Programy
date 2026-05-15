const Triangle = function () {
    let canvas_color = [0.5, 0.0, 0.0]; // RGB
    const canvas = document.getElementById('main-canvas');
    const gl = canvas.getContext('webgl2');

    gl.clearColor(...canvas_color, 1.0);
    gl.clear(gl.COLOR_BUFFER_BIT);

    // --- SHADERY ---
    const vertexShader = gl.createShader(gl.VERTEX_SHADER);
    const fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);

    gl.shaderSource(vertexShader, vertexShaderTxt);
    gl.shaderSource(fragmentShader, fragmentShaderTxt);

    gl.compileShader(vertexShader);
    gl.compileShader(fragmentShader);

    const program = gl.createProgram();
    gl.attachShader(program, vertexShader);
    gl.attachShader(program, fragmentShader);
    gl.linkProgram(program);
    gl.validateProgram(program);

    function checkShaderCompile(shader) {
        if (!gl.getShaderParameter(shader, gl.COMPILE_STATUS)) {
            console.error('shader not compiled', gl.getShaderInfoLog(shader));
        }
    }

    function checkLink(program) {
        if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
            console.error('ERROR linking program!', gl.getProgramInfoLog(program));
        }
    }

    checkShaderCompile(vertexShader);
    checkShaderCompile(fragmentShader);
    checkLink(program);

    // --- PROGRAM I ATRYBUTY ---
    gl.useProgram(program);

    const posAttribLocation = gl.getAttribLocation(program, 'vertPosition');
    const colorAttribLocation = gl.getAttribLocation(program, 'vertColor');

    // --- GLM ---
    const glm = {
        mat4: mat4,
        vec3: vec3,
        quat: quat,
        glMatrix: glMatrix,
    };

    // --- DANE TRÓJKĄTA ---
    let triangleVertices = [
        //  X,    Y,    Z
         0.0,  0.5,  0.0,
        -0.5, -0.5,  0.0,
         0.5, -0.5,  0.0,
    ];

    let triangleColors = [
        1.0, 0.0, 0.0,  // czerwony
        0.0, 1.0, 0.0,  // zielony
        0.0, 0.0, 1.0,  // niebieski
    ];

    // --- BUFORY TRÓJKĄTA ---
    const triangleBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, triangleBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(triangleVertices), gl.STATIC_DRAW);

    const triangleColorBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, triangleColorBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(triangleColors), gl.STATIC_DRAW);

    // --- DANE KWADRATU ---
    let squareVertices = [
        -0.5,  0.5,  0.0,  // lewy górny
        -0.5, -0.5,  0.0,  // lewy dolny
         0.5, -0.5,  0.0,  // prawy dolny

        -0.5,  0.5,  0.0,  // lewy górny
         0.5, -0.5,  0.0,  // prawy dolny
         0.5,  0.5,  0.0,  // prawy górny
    ];

    let squareColors = [
        1.0, 1.0, 0.0,
        1.0, 0.0, 1.0,
        0.0, 1.0, 1.0,
        1.0, 1.0, 0.0,
        0.0, 1.0, 1.0,
        1.0, 0.5, 0.0,
    ];

    // --- BUFORY KWADRATU ---
    const squareBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, squareBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(squareVertices), gl.STATIC_DRAW);

    const squareColorBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, squareColorBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(squareColors), gl.STATIC_DRAW);


    // KOŁO
    const circleVertices = [];
    const segs = 64;
    for (let i = 0; i < segs; i++) {
        const a1 = (i / segs) * Math.PI * 2;
        const a2 = ((i + 1) / segs) * Math.PI * 2;
        circleVertices.push(
            0.0, 0.0, 0.0,                                    // środek
            Math.cos(a1) * 0.5, Math.sin(a1) * 0.5, 0.0,    // punkt na obwodzie
            Math.cos(a2) * 0.5, Math.sin(a2) * 0.5, 0.0,    // następny punkt
        );
    }

    const circleColors = [];
    for (let i = 0; i < segs * 3; i++) {
        circleColors.push(0.4, 0.2, 1.0);  // fioletowy, możesz zmienić
    }

    // --- BUFORY KOŁA ---
    const circleBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, circleBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(circleVertices), gl.STATIC_DRAW);

    const circleColorBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, circleColorBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(circleColors), gl.STATIC_DRAW);


    // --- MACIERZE ---
    const modelMatrix = gl.getUniformLocation(program, 'mModel');
    const viewMatrix = gl.getUniformLocation(program, 'mView');
    const projMatrix = gl.getUniformLocation(program, 'mProj');
    let mModCircle = glm.mat4.create();

    let mMod = glm.mat4.create();
    let mModSquare = glm.mat4.create();

    let mView = glm.mat4.create();
    glm.mat4.lookAt(mView, [0, 0, 10], [0, 0, 0], [0, 1, 0]);

    let mProj = glm.mat4.create();
    glm.mat4.perspective(mProj, glm.glMatrix.toRadian(45), canvas.width / canvas.height, 0.1, 1000.0);

    gl.uniformMatrix4fv(viewMatrix, false, mView);
    gl.uniformMatrix4fv(projMatrix, false, mProj);

    let rotation = glm.quat.create();

    const loop = function () {
        const angle = performance.now() / 1000;

        gl.clearColor(...canvas_color, 1.0);
        gl.clear(gl.COLOR_BUFFER_BIT);

        // TRÓJKĄT – obrót w lewo, pozycja po lewej
        glm.quat.setAxisAngle(rotation, [0, 1, 0], angle);
        glm.mat4.fromRotationTranslationScale(
            mMod,
            rotation,
            glm.vec3.fromValues(-0.6, 0, 0),
            glm.vec3.fromValues(1, 1, 1)
        );
        gl.uniformMatrix4fv(modelMatrix, false, mMod);

        gl.bindBuffer(gl.ARRAY_BUFFER, triangleBuffer);
        gl.vertexAttribPointer(posAttribLocation, 3, gl.FLOAT, false, 3 * Float32Array.BYTES_PER_ELEMENT, 0);
        gl.enableVertexAttribArray(posAttribLocation);

        gl.bindBuffer(gl.ARRAY_BUFFER, triangleColorBuffer);
        gl.vertexAttribPointer(colorAttribLocation, 3, gl.FLOAT, false, 3 * Float32Array.BYTES_PER_ELEMENT, 0);
        gl.enableVertexAttribArray(colorAttribLocation);

        gl.drawArrays(gl.TRIANGLES, 0, 3);

        // KWADRAT – obrót w prawo, pozycja po prawej
        let rotSquare = glm.quat.create();
        glm.quat.setAxisAngle(rotSquare, [0, 1, 0], -angle);
        glm.mat4.fromRotationTranslationScale(
            mModSquare,
            rotSquare,
            glm.vec3.fromValues(0.6, 0, 0),
            glm.vec3.fromValues(1, 1, 1)
        );
        gl.uniformMatrix4fv(modelMatrix, false, mModSquare);

        gl.bindBuffer(gl.ARRAY_BUFFER, squareBuffer);
        gl.vertexAttribPointer(posAttribLocation, 3, gl.FLOAT, false, 3 * Float32Array.BYTES_PER_ELEMENT, 0);
        gl.enableVertexAttribArray(posAttribLocation);

        gl.bindBuffer(gl.ARRAY_BUFFER, squareColorBuffer);
        gl.vertexAttribPointer(colorAttribLocation, 3, gl.FLOAT, false, 3 * Float32Array.BYTES_PER_ELEMENT, 0);
        gl.enableVertexAttribArray(colorAttribLocation);

        gl.drawArrays(gl.TRIANGLES, 0, 6);

        requestAnimationFrame(loop);


        // KOŁO – obrót w górę (wokół osi X), pozycja na środku
        let rotCircle = glm.quat.create();
        glm.quat.setAxisAngle(rotCircle, [1, 0, 0], angle);  // oś X dla urozmaicenia
        glm.mat4.fromRotationTranslationScale(
            mModCircle,
            rotCircle,
            glm.vec3.fromValues(0.0, 0.0, 0.0),  // środek ekranu
            glm.vec3.fromValues(1, 1, 1)
        );
        gl.uniformMatrix4fv(modelMatrix, false, mModCircle);

        gl.bindBuffer(gl.ARRAY_BUFFER, circleBuffer);
        gl.vertexAttribPointer(posAttribLocation, 3, gl.FLOAT, false, 3 * Float32Array.BYTES_PER_ELEMENT, 0);
        gl.enableVertexAttribArray(posAttribLocation);

        gl.bindBuffer(gl.ARRAY_BUFFER, circleColorBuffer);
        gl.vertexAttribPointer(colorAttribLocation, 3, gl.FLOAT, false, 3 * Float32Array.BYTES_PER_ELEMENT, 0);
        gl.enableVertexAttribArray(colorAttribLocation);

        gl.drawArrays(gl.TRIANGLES, 0, segs * 3);  // 64 * 3 = 192 wierzchołki
    };

    requestAnimationFrame(loop);
};