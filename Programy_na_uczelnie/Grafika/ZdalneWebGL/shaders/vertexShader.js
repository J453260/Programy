const vertexShaderTxt = `
precision mediump float;

attribute vec3 vertPosition;   // vec3 zamiast vec2
attribute vec3 vertColor;

varying vec3 fragColor;

uniform mat4 mModel;           // macierze z script.js
uniform mat4 mView;
uniform mat4 mProj;

void main() {
    fragColor = vertColor;
    gl_Position = mProj * mView * mModel * vec4(vertPosition, 1.0);
}
`;
// uniform are per-primitive parameters (constant during an entire draw call) ;
// attribute are per-vertex parameters (typically : positions, normals, colors, UVs, ...) ;
// varying are per-fragment (or per-pixel) parameters : they vary from pixels to pixels.