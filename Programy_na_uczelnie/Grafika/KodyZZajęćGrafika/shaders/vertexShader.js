const vertexShaderTxt = `
precision mediump float;

attribute vec2 vertPosition;
attribute vec3 vertColor;

varying vec3 fragColor;

void main() {
    fragColor = vertColor;
    gl_Position = vec4(vertPosition, 0.0, 1.0);
}
`
// uniform are per-primitive parameters (constant during an entire draw call) ;
// attribute are per-vertex parameters (typically : positions, normals, colors, UVs, ...) ;
// varying are per-fragment (or per-pixel) parameters : they vary from pixels to pixels.