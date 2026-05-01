function changeColors() {
    const rand = () => Math.random();
    drawShapes(
        [rand(), rand(), rand()],
        [rand(), rand(), rand()],
        [rand(), rand(), rand()],
    );
}


function drawShapes(squareColor, hexColor, circleColor) {
    gl.clear(gl.COLOR_BUFFER_BIT);

    const squareVertices = [
        -0.9,  0.5,   ...squareColor,
        -0.9, -0.5,   ...squareColor,
        -0.4,  0.5,   ...squareColor,
        -0.9, -0.5,   ...squareColor,
        -0.4, -0.5,   ...squareColor,
        -0.4,  0.5,   ...squareColor,
    ];

    const hexVertices = [];
    for (let i = 0; i < 6; i++) {
        const a1 = (i / 6) * Math.PI * 2 - Math.PI / 2;
        const a2 = ((i + 1) / 6) * Math.PI * 2 - Math.PI / 2;
        hexVertices.push(
            0.15, 0.0,  ...hexColor,
            0.15 + Math.cos(a1) * 0.35, Math.sin(a1) * 0.5,  ...hexColor,
            0.15 + Math.cos(a2) * 0.35, Math.sin(a2) * 0.5,  ...hexColor,
        );
    }

    const circleVertices = [];
    const segs = 64;
    for (let i = 0; i < segs; i++) {
        const a1 = (i / segs) * Math.PI * 2;
        const a2 = ((i + 1) / segs) * Math.PI * 2;
        circleVertices.push(
            0.7, 0.0,  ...circleColor,
            0.7 + Math.cos(a1) * 0.25, Math.sin(a1) * 0.35,  ...circleColor,
            0.7 + Math.cos(a2) * 0.25, Math.sin(a2) * 0.35,  ...circleColor,
        );
    }

    bindAndDraw(squareVertices, 6);
    bindAndDraw(hexVertices, 6 * 3);
    bindAndDraw(circleVertices, segs * 3);
}



let gl, posAttribLocation, colorAttribLocation;

function bindAndDraw(vertices, count) {
    const buffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);

    gl.vertexAttribPointer(posAttribLocation, 2, gl.FLOAT, false, 5 * Float32Array.BYTES_PER_ELEMENT, 0);
    gl.vertexAttribPointer(colorAttribLocation, 3, gl.FLOAT, false, 5 * Float32Array.BYTES_PER_ELEMENT, 2 * Float32Array.BYTES_PER_ELEMENT);
    gl.enableVertexAttribArray(posAttribLocation);
    gl.enableVertexAttribArray(colorAttribLocation);

    gl.drawArrays(gl.TRIANGLES, 0, count);
}


const Triangle = function () {
    // code goes here

    //const canvas = document.getElementById('main-canvas');
    //gl = canvas.getContext('webgl2');
    
    let canvas_color = [0.25, 0.44, 0.8]; // RGB
    const canvas = document.getElementById('main-canvas');
    gl = canvas.getContext('webgl2');
    
    gl.clearColor(...canvas_color, 1.0);   // rgba
    gl.clear(gl.COLOR_BUFFER_BIT);

    const vertexShader = gl.createShader(gl.VERTEX_SHADER);
    const fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);

    gl.shaderSource(vertexShader, vertexShaderTxt);
    gl.shaderSource(fragmentShader, fragmentShaderTxt);

    gl.compileShader(vertexShader);
    gl.compileShader(fragmentShader);

    const program = gl.createProgram();

    gl.attachShader(program, vertexShader);     // program will use those shaders
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

    posAttribLocation = gl.getAttribLocation(program, 'vertPosition');
    colorAttribLocation = gl.getAttribLocation(program, 'vertColor');

    gl.useProgram(program);     // specify which program to use
    drawShapes([1.0, 0.2, 0.2],  [0.9, 0.7, 0.1],  [0.4, 0.2, 1.0]);
}