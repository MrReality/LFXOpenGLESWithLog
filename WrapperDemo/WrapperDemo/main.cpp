//
//  main.cpp
//  WrapperDemo
//
//  Created by michael on 25/05/2018.
//  Copyright © 2018 michael.laifx. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl3.h>
#include "LFXOpenGLES.hpp"

static const char* kTextureSamplerNameString = "inputImageTexture1";

static const char* kPassThroughVertexShaderString = R"(
attribute vec3 attPosition;
attribute vec2 attUV;
varying vec2   textureCoordinate;
void main(void) {
    gl_Position = vec4(attPosition, 1.);
    textureCoordinate = attUV;
}
)";

static const char* kPassThroughFragmentShaderString = R"( precision highp float;
uniform sampler2D inputImageTexture1;
varying vec2 textureCoordinate;

void main() {
    gl_FragColor = texture2D(inputImageTexture1, textureCoordinate);
}
)";

int main(int argc, const char *argv[]) {
    auto label = "ParticleVertexShader";
    GLuint program;
    GLuint vShader;
    GLboolean isVShader;
    GLuint fShader;
    GLboolean isFShader;
    GLuint bufferSize = 1024;
    GLchar infolog[1024];
    GLint param;

    gl.CreateShader(label, GL_VERTEX_SHADER, vShader)
            .ShaderSource(label, vShader, 1, &kPassThroughVertexShaderString, nullptr)
            .CompileShader(label, vShader)
            .GetShaderInfoLog(label, vShader, bufferSize, nullptr, infolog)
            .GetShaderiv(label, vShader, GL_COMPILE_STATUS, &param)
            .DeleteShader(label, vShader)
        .IsShader(label, vShader, isVShader)
        .ShaderBinary(1, &vShader, GL_SHADER_BINARY_FORMATS, nullptr, 0)
        .ReleaseShaderCompiler()
            ;

//
//    gl.CreateProgram(label, program)
//            .AttachShader(label, program, vShader)
//            .AttachShader(label, program, fShader)
//            .LinkProgram(label, program)
//            .GetProgramInfoLog(label, program, bufferSize, nullptr, infolog);
    return 0;
}