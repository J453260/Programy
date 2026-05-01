const Triangle = function () {
    // code goes here
    
    let canvas_color = [0.25, 0.44, 0.8]; // RGB
    const canvas = document.getElementById('main-canvas');
    const gl = canvas.getContext('webgl2');
    
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

    let triangleVertices =
    [ //  X,  Y         R,   G,    B
        0.0, 0.5,       1.0, 0.0, 0.0,
        -0.5, -0.5,     0.0, 1.0, 0.0,
        0.5, -0.5,       0.0, 0.0, 1.0,
    ];

    const triangleBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, triangleBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(triangleVertices), gl.STATIC_DRAW);

    const posAttribLocation = gl.getAttribLocation(program, 'vertPosition');
    gl.vertexAttribPointer(
        posAttribLocation,
        2,  // number of components (here is 2, bs we are in 2d space)
        gl.FLOAT, // type of that attrib, localization is in floats
        0,      // if the thing should be normalized
        5*Float32Array.BYTES_PER_ELEMENT, // STRIDE offset in bytes 
        0, // offset specifying an offset in bytes
    );
    gl.enableVertexAttribArray(posAttribLocation);

    const colorAttribLocation = gl.getAttribLocation(program, 'vertColor');
    gl.vertexAttribPointer(
        colorAttribLocation,
        3,          // 3 bcs RGB
        gl.FLOAT,
        0,
        5*Float32Array.BYTES_PER_ELEMENT,
        2*Float32Array.BYTES_PER_ELEMENT,   // here offset is nonzero bcs we SKIP first 2 values
    )
    gl.enableVertexAttribArray(colorAttribLocation);

    gl.useProgram(program);     // specify which program to use
    gl.drawArrays(gl.TRIANGLES, 0, 3); 
}
