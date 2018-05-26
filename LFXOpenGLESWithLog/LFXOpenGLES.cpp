#include "LFXOpenGLES.hpp"

#define LFX_C_STRING(str) #str

#define glError() { \
GLenum err = glGetError(); \
if (err != GL_NO_ERROR) { \
printf("glError: %04x caught at %s:%u\n", err, __FILE__, __LINE__); \
} \
}

//size_t getShaderArgumentDataTypeSizeInByte(ShaderArgumentDataType type, int elementCount)
//{
//    size_t sizeInByte = 0;
//    switch (type)
//    {
//    case ShaderArgumentDataTypeInteger:
//    case ShaderArgumentDataTypeIntegerArray:
//        sizeInByte = sizeof(GLint);
//        break;
//    case ShaderArgumentDataTypeFloat:;
//    case ShaderArgumentDataTypeFloatArray:
//        sizeInByte = sizeof(GLfloat) * elementCount;
//        break;
//    case ShaderArgumentDataTypeVector2:
//        sizeInByte = sizeof(GLfloat) * 2;
//        break;
//    case ShaderArgumentDataTypeVector2Array:
//        sizeInByte = sizeof(GLfloat) * 2 * elementCount;
//        break;
//    case ShaderArgumentDataTypeVector3:
//        sizeInByte = sizeof(GLfloat) * 3;
//        break;
//    case ShaderArgumentDataTypeVector3Array:
//        sizeInByte = sizeof(GLfloat) * 3 * elementCount;
//        break;
//    case ShaderArgumentDataTypeVector4:
//        sizeInByte = sizeof(GLfloat) * 4;
//        break;
//    case ShaderArgumentDataTypeVector4Array:
//        sizeInByte = sizeof(GLfloat) * 4 * elementCount;
//        break;
//    case ShaderArgumentDataTypeMatrix2:
//        sizeInByte = sizeof(GLfloat) * 4;
//        break;
//    case ShaderArgumentDataTypeMatrix3:
//        sizeInByte = sizeof(GLfloat) * 9;
//        break;
//    case ShaderArgumentDataTypeMatrix4:
//        sizeInByte = sizeof(GLfloat) * 16;
//        break;
//    }
//    return sizeInByte;
//}

//GLenum toGLESType(ShaderArgumentDataType type)
//{
//    GLenum glType = GL_FLOAT;
//    switch (type)
//    {
//    case ShaderArgumentDataTypeInteger:
//    case ShaderArgumentDataTypeIntegerArray:
//    {
//        glType = GL_INT;
//    }
//        break;
//    case ShaderArgumentDataTypeFloat:;
//    case ShaderArgumentDataTypeFloatArray:
//    case ShaderArgumentDataTypeVector2:
//    case ShaderArgumentDataTypeVector3:
//    case ShaderArgumentDataTypeVector3Array:
//    case ShaderArgumentDataTypeVector4:
//    case ShaderArgumentDataTypeVector4Array:
//    case ShaderArgumentDataTypeMatrix3:
//    case ShaderArgumentDataTypeMatrix4:
//    {
//        glType = GL_FLOAT;
//    }
//        break;
//    }
//    return glType;
//}

//ShaderArgumentDataType toShaderArgumentDataType(GLenum type)
//{
//    ShaderArgumentDataType shaderDataType = ShaderArgumentDataTypeInteger;
//    switch (type)
//    {
//    case GL_FLOAT:
//        shaderDataType = ShaderArgumentDataTypeFloat;
//        break;
//    case GL_FLOAT_VEC2:
//        shaderDataType = ShaderArgumentDataTypeVector2;
//        break;
//    case GL_FLOAT_VEC3:
//        shaderDataType = ShaderArgumentDataTypeVector3;
//        break;
//    case GL_FLOAT_VEC4:
//        shaderDataType = ShaderArgumentDataTypeVector4;
//        break;
//    case GL_INT:
//        shaderDataType = ShaderArgumentDataTypeInteger;
//        break;
//    case GL_INT_VEC2:
//    case GL_INT_VEC3:
//    case GL_INT_VEC4:
//    case GL_BOOL:
//    case GL_BOOL_VEC2:
//    case GL_BOOL_VEC3:
//    case GL_BOOL_VEC4:
//        break;
//    case GL_FLOAT_MAT2:
//        shaderDataType = ShaderArgumentDataTypeMatrix2;
//        break;
//    case GL_FLOAT_MAT3:
//        shaderDataType = ShaderArgumentDataTypeMatrix3;
//        break;
//    case GL_FLOAT_MAT4:
//        shaderDataType = ShaderArgumentDataTypeMatrix4;
//        break;
//    case GL_SAMPLER_2D:
//        shaderDataType = ShaderArgumentDataTypeSampler2D;
//        break;
//    case GL_SAMPLER_CUBE:
//        shaderDataType = ShaderArgumentDataTypeSamplerCube;
//        break;
//    default:
//        break;
//    }
//    return shaderDataType;
//}

string toLFXOpenGLESLiteral(GLESMacro type, GLint value) {
    string valueLiteral = "not a valid GL type";
    switch (type) {
        case ClearBufferMask:
            switch (value) {
                case GL_DEPTH_BUFFER_BIT:
                    valueLiteral = LFX_C_STRING(GL_DEPTH_BUFFER_BIT);
                    break;
                case GL_STENCIL_BUFFER_BIT:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_BUFFER_BIT);
                    break;
                case GL_COLOR_BUFFER_BIT:
                    valueLiteral = LFX_C_STRING(GL_COLOR_BUFFER_BIT);
                    break;
                default:
                    break;
            }
            break;
        case BeginMode:
            switch (value) {
                case GL_POINTS:
                    valueLiteral = LFX_C_STRING(GL_POINTS);
                    break;
                case GL_LINES:
                    valueLiteral = LFX_C_STRING(GL_LINES);
                    break;
                case GL_LINE_LOOP:
                    valueLiteral = LFX_C_STRING(GL_LINE_LOOP);
                    break;
                case GL_LINE_STRIP:
                    valueLiteral = LFX_C_STRING(GL_LINE_STRIP);
                    break;
                case GL_TRIANGLES:
                    valueLiteral = LFX_C_STRING(GL_TRIANGLES);
                    break;
                case GL_TRIANGLE_STRIP:
                    valueLiteral = LFX_C_STRING(GL_TRIANGLE_STRIP);
                    break;
                case GL_TRIANGLE_FAN:
                    valueLiteral = LFX_C_STRING(GL_TRIANGLE_FAN);
                    break;
                default:
                    break;
            }
            break;
        case Blend:
            switch (value) {
                case GL_ZERO:
                    valueLiteral = LFX_C_STRING(GL_ZERO);
                    break;
                case GL_ONE:
                    valueLiteral = LFX_C_STRING(GL_ONE);
                    break;
                case GL_SRC_COLOR:
                    valueLiteral = LFX_C_STRING(GL_SRC_COLOR);
                    break;
                case GL_ONE_MINUS_SRC_COLOR:
                    valueLiteral = LFX_C_STRING(GL_ONE_MINUS_SRC_COLOR);
                    break;
                case GL_SRC_ALPHA:
                    valueLiteral = LFX_C_STRING(GL_SRC_ALPHA);
                    break;
                case GL_ONE_MINUS_SRC_ALPHA:
                    valueLiteral = LFX_C_STRING(GL_ONE_MINUS_SRC_ALPHA);
                    break;
                case GL_DST_ALPHA:
                    valueLiteral = LFX_C_STRING(GL_DST_ALPHA);
                    break;
                case GL_ONE_MINUS_DST_ALPHA:
                    valueLiteral = LFX_C_STRING(GL_ONE_MINUS_DST_ALPHA);
                    break;
                case GL_DST_COLOR:
                    valueLiteral = LFX_C_STRING(GL_DST_COLOR);
                    break;
                case GL_ONE_MINUS_DST_COLOR:
                    valueLiteral = LFX_C_STRING(GL_ONE_MINUS_DST_COLOR);
                    break;
                case GL_SRC_ALPHA_SATURATE:
                    valueLiteral = LFX_C_STRING(GL_SRC_ALPHA_SATURATE);
                    break;
                case GL_FUNC_ADD:
                    valueLiteral = LFX_C_STRING(GL_FUNC_ADD);
                    break;
                case GL_BLEND_EQUATION:
                    valueLiteral = LFX_C_STRING(GL_BLEND_EQUATION);
                    break;
                case GL_BLEND_EQUATION_ALPHA:
                    valueLiteral = LFX_C_STRING(GL_BLEND_EQUATION_ALPHA);
                    break;
                case GL_FUNC_SUBTRACT:
                    valueLiteral = LFX_C_STRING(GL_FUNC_SUBTRACT);
                    break;
                case GL_FUNC_REVERSE_SUBTRACT:
                    valueLiteral = LFX_C_STRING(GL_FUNC_REVERSE_SUBTRACT);
                    break;
                case GL_BLEND_DST_RGB:
                    valueLiteral = LFX_C_STRING(GL_BLEND_DST_RGB);
                    break;
                case GL_BLEND_SRC_RGB:
                    valueLiteral = LFX_C_STRING(GL_BLEND_SRC_RGB);
                    break;
                case GL_BLEND_DST_ALPHA:
                    valueLiteral = LFX_C_STRING(GL_BLEND_DST_ALPHA);
                    break;
                case GL_BLEND_SRC_ALPHA:
                    valueLiteral = LFX_C_STRING(GL_BLEND_SRC_ALPHA);
                    break;
                case GL_CONSTANT_COLOR:
                    valueLiteral = LFX_C_STRING(GL_CONSTANT_COLOR);
                    break;
                case GL_ONE_MINUS_CONSTANT_COLOR:
                    valueLiteral = LFX_C_STRING(GL_ONE_MINUS_CONSTANT_COLOR);
                    break;
                case GL_CONSTANT_ALPHA:
                    valueLiteral = LFX_C_STRING(GL_CONSTANT_ALPHA);
                    break;
                case GL_ONE_MINUS_CONSTANT_ALPHA:
                    valueLiteral = LFX_C_STRING(GL_ONE_MINUS_CONSTANT_ALPHA);
                    break;
                case GL_BLEND_COLOR:
                    valueLiteral = LFX_C_STRING(GL_BLEND_COLOR);
                    break;
                default:
                    break;
            }
            break;
        case LFXOpenGLESParamsName:
            switch (value) {
                case GL_SHADER_TYPE:
                    valueLiteral = LFX_C_STRING(GL_SHADER_TYPE);
                    break;
                case GL_DELETE_STATUS:
                    valueLiteral = LFX_C_STRING(GL_DELETE_STATUS);
                    break;
                case GL_COMPILE_STATUS:
                    valueLiteral = LFX_C_STRING(GL_COMPILE_STATUS);
                    break;
                case GL_INFO_LOG_LENGTH:
                    valueLiteral = LFX_C_STRING(GL_INFO_LOG_LENGTH);
                    break;
                case GL_SHADER_SOURCE_LENGTH:
                    valueLiteral = LFX_C_STRING(GL_SHADER_SOURCE_LENGTH);
                    break;
                case GL_LINK_STATUS:
                    valueLiteral = LFX_C_STRING(GL_LINK_STATUS);
                    break;
                case GL_VALIDATE_STATUS:
                    valueLiteral = LFX_C_STRING(GL_VALIDATE_STATUS);
                    break;
                case GL_ACTIVE_UNIFORMS:
                    valueLiteral = LFX_C_STRING(GL_ACTIVE_UNIFORMS);
                    break;
                case GL_ACTIVE_ATTRIBUTES:
                    valueLiteral = LFX_C_STRING(GL_ACTIVE_ATTRIBUTES);
                    break;
                case GL_LINE_WIDTH:
                    valueLiteral = LFX_C_STRING(GL_LINE_WIDTH);
                    break;
                case GL_ALIASED_POINT_SIZE_RANGE:
                    valueLiteral = LFX_C_STRING(GL_ALIASED_POINT_SIZE_RANGE);
                    break;
                case GL_ALIASED_LINE_WIDTH_RANGE:
                    valueLiteral = LFX_C_STRING(GL_ALIASED_LINE_WIDTH_RANGE);
                    break;
                case GL_CULL_FACE_MODE:
                    valueLiteral = LFX_C_STRING(GL_CULL_FACE_MODE);
                    break;
                case GL_FRONT_FACE:
                    valueLiteral = LFX_C_STRING(GL_FRONT_FACE);
                    break;
                case GL_DEPTH_RANGE:
                    valueLiteral = LFX_C_STRING(GL_DEPTH_RANGE);
                    break;
                case GL_DEPTH_WRITEMASK:
                    valueLiteral = LFX_C_STRING(GL_DEPTH_WRITEMASK);
                    break;
                case GL_DEPTH_CLEAR_VALUE:
                    valueLiteral = LFX_C_STRING(GL_DEPTH_CLEAR_VALUE);
                    break;
                case GL_DEPTH_FUNC:
                    valueLiteral = LFX_C_STRING(GL_DEPTH_FUNC);
                    break;
                case GL_STENCIL_CLEAR_VALUE:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_CLEAR_VALUE);
                    break;
                case GL_STENCIL_FUNC:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_FUNC);
                    break;
                case GL_STENCIL_FAIL:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_FAIL);
                    break;
                case GL_STENCIL_PASS_DEPTH_FAIL:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_PASS_DEPTH_FAIL);
                    break;
                case GL_STENCIL_PASS_DEPTH_PASS:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_PASS_DEPTH_PASS);
                    break;
                case GL_STENCIL_REF:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_REF);
                    break;
                case GL_STENCIL_VALUE_MASK:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_VALUE_MASK);
                    break;
                case GL_STENCIL_WRITEMASK:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_WRITEMASK);
                    break;
                case GL_STENCIL_BACK_FUNC:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_BACK_FUNC);
                    break;
                case GL_STENCIL_BACK_FAIL:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_BACK_FAIL);
                    break;
                case GL_STENCIL_BACK_PASS_DEPTH_FAIL:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_BACK_PASS_DEPTH_FAIL);
                    break;
                case GL_STENCIL_BACK_PASS_DEPTH_PASS:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_BACK_PASS_DEPTH_PASS);
                    break;
                case GL_STENCIL_BACK_REF:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_BACK_REF);
                    break;
                case GL_STENCIL_BACK_VALUE_MASK:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_BACK_VALUE_MASK);
                    break;
                case GL_STENCIL_BACK_WRITEMASK:
                    valueLiteral = LFX_C_STRING(GL_STENCIL_BACK_WRITEMASK);
                    break;
                case GL_VIEWPORT:
                    valueLiteral = LFX_C_STRING(GL_VIEWPORT);
                    break;
                case GL_SCISSOR_BOX:
                    valueLiteral = LFX_C_STRING(GL_SCISSOR_BOX);
                    break;
                default:
                    break;
            }
            break;
        case FramebufferObject:
            switch (value) {
                case GL_FRAMEBUFFER:
                    valueLiteral = LFX_C_STRING(GL_FRAMEBUFFER);
                    break;
                case GL_FRAMEBUFFER_COMPLETE:
                    valueLiteral = LFX_C_STRING(GL_FRAMEBUFFER_COMPLETE);
                    break;
                case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
                    valueLiteral = LFX_C_STRING(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT);
                    break;
                case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
                    valueLiteral = LFX_C_STRING(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT);
                    break;
                    //                case GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS:
                    //                    valueLiteral = LFX_C_STRING(GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS);
                    break;
                case GL_FRAMEBUFFER_UNSUPPORTED:
                    valueLiteral = LFX_C_STRING(GL_FRAMEBUFFER_UNSUPPORTED);
                    break;
                case GL_COLOR_ATTACHMENT0:
                    valueLiteral = LFX_C_STRING(GL_COLOR_ATTACHMENT0);
                    break;
                case GL_COLOR_ATTACHMENT1:
                    valueLiteral = LFX_C_STRING(GL_COLOR_ATTACHMENT1);
                    break;
                default:
                    break;
            }
            break;
        case TextureUnit:
            switch (value) {
                case GL_TEXTURE0:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE0);
                    break;
                case GL_TEXTURE1:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE1);
                    break;
                case GL_TEXTURE2:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE2);
                    break;
                case GL_TEXTURE3:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE3);
                    break;
                case GL_TEXTURE4:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE4);
                    break;
                case GL_TEXTURE5:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE5);
                    break;
                case GL_TEXTURE6:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE6);
                    break;
                case GL_TEXTURE7:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE7);
                    break;
                case GL_TEXTURE8:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE8);
                    break;
                case GL_TEXTURE9:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE9);
                    break;
                case GL_TEXTURE10:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE10);
                    break;
                default:
                    break;
            }
            break;
        case TextureTarget:
            switch (value) {
                case GL_TEXTURE_2D:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE_2D);
                    break;
                case GL_TEXTURE_CUBE_MAP:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE_CUBE_MAP);
                    break;
                case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
                    break;
                case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
                    break;
                case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);
                    break;
                case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE_CUBE_MAP_POSITIVE_X);
                    break;
                case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
                    break;
                case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
                    valueLiteral = LFX_C_STRING(GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
                    break;
                default:
                    break;
            }
            break;
        case GLESMacroTexture:
            switch (value) {
                case GL_RGBA:
                    valueLiteral = LFX_C_STRING(GL_RGBA);
                    break;
                case GL_BGRA:
                    valueLiteral = LFX_C_STRING(GL_BGRA);
                    break;
                case GL_ALPHA:
                    valueLiteral = LFX_C_STRING(GL_ALPHA);
                    break;
                case GL_RGB:
                    valueLiteral = LFX_C_STRING(GL_RGB);
                    break;
                case GL_LUMINANCE:
                    valueLiteral = LFX_C_STRING(GL_LUMINANCE);
                    break;
                case GL_LUMINANCE_ALPHA:
                    valueLiteral = LFX_C_STRING(GL_LUMINANCE_ALPHA);
                    break;
                default:
                    break;
            }
            break;
        case LFXOpenGLESShaderType:
            switch (value) {
                case GL_VERTEX_SHADER:
                    valueLiteral = LFX_C_STRING(GL_VERTEX_SHADER);
                    break;
                case GL_FRAGMENT_SHADER:
                    valueLiteral = LFX_C_STRING(GL_FRAGMENT_SHADER);
                    break;
                default:
                    break;
            }
            break;
        case LFXOpenGLESBoolean:
            switch (value) {
                case GL_TRUE:
                    valueLiteral = LFX_C_STRING(GL_TRUE);
                    break;
                case GL_FALSE:
                    valueLiteral = LFX_C_STRING(GL_FALSE);
                    break;
                default:
                    break;
            }
            break;
        case GLESMacroShaderDataType:
            switch (value) {
                case GL_FLOAT:
                    valueLiteral = "float";
                    break;
                case GL_FLOAT_VEC2:
                    valueLiteral = "vec2";
                    break;
                case GL_FLOAT_VEC3:
                    valueLiteral = "vec3";
                    break;
                case GL_FLOAT_VEC4:
                    valueLiteral = "vec4";
                    break;
                case GL_INT:
                    valueLiteral = "int";
                    break;
                case GL_INT_VEC2:
                    valueLiteral = "ivec2";
                    break;
                case GL_INT_VEC3:
                    valueLiteral = "ivec3";
                    break;
                case GL_INT_VEC4:
                    valueLiteral = "ivec4";
                    break;
                case GL_BOOL:
                    valueLiteral = "bool";
                    break;
                case GL_BOOL_VEC2:
                    valueLiteral = "bvec2";
                    break;
                case GL_BOOL_VEC3:
                    valueLiteral = "bvec3";
                    break;
                case GL_BOOL_VEC4:
                    valueLiteral = "bvec4";
                    break;
                case GL_FLOAT_MAT2:
                    valueLiteral = "mat2";
                    break;
                case GL_FLOAT_MAT3:
                    valueLiteral = "mat3";
                    break;
                case GL_FLOAT_MAT4:
                    valueLiteral = "mat4";
                    break;
                case GL_SAMPLER_2D:
                    valueLiteral = "sampler2D";
                    break;
                case GL_SAMPLER_CUBE:
                    valueLiteral = "samplerCube";
                    break;
                default:
                    valueLiteral = LFX_C_STRING(value);
                    break;
            }
            break;
        case GLESMacroDataType:
            switch (value) {
                case GL_BYTE:
                    valueLiteral = LFX_C_STRING(GL_BYTE);
                    break;
                case GL_UNSIGNED_BYTE:
                    valueLiteral = LFX_C_STRING(GL_UNSIGNED_BYTE);
                    break;
                case GL_SHORT:
                    valueLiteral = LFX_C_STRING(GL_SHORT);
                    break;
                case GL_UNSIGNED_SHORT:
                    valueLiteral = LFX_C_STRING(GL_UNSIGNED_SHORT);
                    break;
                case GL_INT:
                    valueLiteral = LFX_C_STRING(GL_INT);
                    break;
                case GL_UNSIGNED_INT:
                    valueLiteral = LFX_C_STRING(GL_UNSIGNED_INT);
                    break;
                case GL_HALF_FLOAT:
                    valueLiteral = LFX_C_STRING(GL_HALF_FLOAT);
                    break;
                case GL_FLOAT:
                    valueLiteral = LFX_C_STRING(GL_FLOAT);
                    break;
                    //                case GL_DOUBLE:
                    //                    valueLiteral = LFX_C_STRING(GL_DOUBLE);
                    //                    break;
                    //                case GL_FIXED:
                    //                    valueLiteral = LFX_C_STRING(GL_FIXED);
                    break;
                    //                case GL_INT_2_10_10_10_REV:
                    //                    valueLiteral = LFX_C_STRING(GL_INT_2_10_10_10_REV);
                    break;
                    //                case GL_UNSIGNED_INT_2_10_10_10_REV:
                    //                    valueLiteral = LFX_C_STRING(GL_UNSIGNED_INT_2_10_10_10_REV);
                    break;
                    //                case GL_UNSIGNED_INT_10F_11F_11F_REV:
                    //                    valueLiteral = LFX_C_STRING(GL_UNSIGNED_INT_10F_11F_11F_REV);
                    break;
                default:
                    break;
            }
            break;
        case BufferObjects:
            break;
        case CullFaceMode:
            break;
        case DepthFunction:
            break;
        case ErrorCode:
            break;
        case GetTextureParameter:
            break;
        case TextureMagFilter:
            break;
        case TextureMinFilter:
            break;
        case TextureParameterName:
            break;
        case HintMode:
            break;
        case HintTarget:
            break;
        case GLESMacroPixelFormat:
            break;
        case PixelType:
            break;
        case StencilFunction:
            break;
        case StencilOp:
            break;
        case StringName:
            break;
    }
    
    return valueLiteral;
}


//GLint toGLESComponentCount(ShaderArgumentDataType type)
//{
//    GLint componentCount = 0;
//    switch (type)
//    {
//    case ShaderArgumentDataTypeInteger:
//    case ShaderArgumentDataTypeIntegerArray:
//    case ShaderArgumentDataTypeFloat:;
//    case ShaderArgumentDataTypeFloatArray:
//    {
//        componentCount = 1;
//    }
//        break;
//    case ShaderArgumentDataTypeVector2:
//    case ShaderArgumentDataTypeVector2Array:
//    {
//        componentCount = 2;
//    }
//        break;
//    case ShaderArgumentDataTypeVector3:
//    case ShaderArgumentDataTypeVector3Array:
//    case ShaderArgumentDataTypeMatrix3:
//    case ShaderArgumentDataTypeMatrix3Array:
//    {
//        componentCount = 3;
//    }
//        break;
//    case ShaderArgumentDataTypeVector4:
//    case ShaderArgumentDataTypeVector4Array:
//    case ShaderArgumentDataTypeMatrix4:
//    case ShaderArgumentDataTypeMatrix4Array:
//    {
//        componentCount = 4;
//    }
//        break;
//    }
//    return componentCount;
//}


//GLenum toGLESPrimitiveType(GI::PrimitiveType primitiveType)
//{
//    GLenum type = GL_TRIANGLES;
//    switch (primitiveType)
//    {
//    default:
//    {
//        LogDebug("primitiveType is invalid\n");
//    }
//        break;
//    case GI::PrimitiveTypePoint:
//    {
//        type = GL_POINTS;
//    }
//        break;
//    case GI::PrimitiveTypeLine:
//    {
//        type = GL_LINES;
//    }
//        break;
//    case GI::PrimitiveTypeLineStrip:
//    {
//        type = GL_LINE_STRIP;
//    }
//        break;
//    case GI::PrimitiveTypeTriangle:
//    {
//        type = GL_TRIANGLES;
//    }
//        break;
//    case GI::PrimitiveTypeTriangleStrip:
//    {
//        type = GL_TRIANGLE_STRIP;
//    }
//        break;
//    }
//    return type;
//}

#pragma mark - OpenGL ES 2.0

#pragma mark Texture

// todo: 逐个输出textures值
const LFXOpenGLES &
LFXOpenGLES::GenTextures(ConstStringRefLabel, GLsizei n, GLuint *textures) const {
    glGenTextures(n, textures);
    if (enableVerboseOutput) {
        LogDebug("glGenTextures(n = %d, textures = %p) -> %d", n, textures, *textures);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::BindTexture(const string &label, GLenum target, GLuint texture) const {
    glBindTexture(target, texture);
    
    if (enableVerboseOutput) {
        LogDebug("glBindTexture(target = %s, texture = %d)", toLFXOpenGLESLiteral(TextureTarget, target).c_str(), texture);
#if GL_EXT_debug_label
        /// GL_TEXTURE 正常工作
        glLabelObjectEXT(GL_TEXTURE, texture, 0, label.c_str());
#endif
    }
    return *this;
}

// todo: 修复日志输出
const LFXOpenGLES &LFXOpenGLES::TexParameterf(const string &label, GLenum target, GLenum pname, GLfloat param) const {
    glTexParameterf(target, pname, param);
    if (enableVerboseOutput) {
        LogDebug("glTexParameterf(target = %s, pname = %s, param = %s)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 toLFXOpenGLESLiteral(LFXOpenGLESParamsName, pname).c_str(),
                 toLFXOpenGLESLiteral(TextureTarget, param).c_str());
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::TexParameterfv(const string &label, GLenum target, GLenum pname, const GLfloat *params) const {
    //    glTexParameterfv(target, pname, params);
    if (enableVerboseOutput) {      /// mix
        LogDebug("glTexParameterfv(target = %s, pname = %s, param = %s)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 toLFXOpenGLESLiteral(LFXOpenGLESParamsName, pname).c_str(),
                 toLFXOpenGLESLiteral(TextureTarget, *params).c_str());
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::TexParameteri(const string &label, GLenum target, GLenum pname, GLint param) const {
    glTexParameteri(target, pname, param);
    if (enableVerboseOutput) {
        LogDebug("glTexParameteri(target = %s, pname = %s, param = %s)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 toLFXOpenGLESLiteral(LFXOpenGLESParamsName, pname).c_str(),
                 toLFXOpenGLESLiteral(TextureTarget, param).c_str());
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::TexParameteriv(const string &label, GLenum target, GLenum pname, const GLint *params) const {
    //glTexParameteriv(target, pname, params);
    if (enableVerboseOutput) {
        LogDebug("glTexParameteriv(target = %d, pname = %d, param = %d)",
                 target,
                 pname,
                 params);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetTexParameterfv(const string &label, GLenum target, GLenum pname, GLfloat *params) const {
    if (enableVerboseOutput) {      /// mix
        LogDebug("glGetTexParameterfv(target = %s, pname = %s, param = %s)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 toLFXOpenGLESLiteral(LFXOpenGLESParamsName, pname).c_str(),
                 toLFXOpenGLESLiteral(TextureTarget, *params).c_str());
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetTexParameteriv(const string &label, GLenum target, GLenum pname, GLint *params) const {
    if (enableVerboseOutput) {      /// mix
        LogDebug("glGetTexParameteriv(target = %s, pname = %s, param = %s)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 toLFXOpenGLESLiteral(LFXOpenGLESParamsName, pname).c_str(),
                 toLFXOpenGLESLiteral(TextureTarget, *params).c_str());
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::TexImage2D(const string &label, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) const {
    glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
    if (enableVerboseOutput) {
        LogDebug("glTexImage2D(target = %s, level = %d, internal format = %s, width = %d, height = %d, border = %d, format = %s, type = %s, pixels = %p)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 level,
                 toLFXOpenGLESLiteral(GLESMacroTexture, internalformat).c_str(),
                 width,
                 height,
                 border,
                 toLFXOpenGLESLiteral(GLESMacroTexture, format).c_str(),
                 toLFXOpenGLESLiteral(GLESMacroDataType, type).c_str(),
                 pixels);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::TexSubImage2D(const string &label, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) const {
    glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
    if (enableVerboseOutput) {
        
        
        LogDebug("glTexSubImage2D(target = %s, level = %d, xoffset = %d, yoffset = %d, width = %d, height = %d, format = %s, type = %s, pixels = %p)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 level,
                 xoffset,
                 yoffset,
                 width,
                 height,
                 toLFXOpenGLESLiteral(GLESMacroTexture, format).c_str(),
                 toLFXOpenGLESLiteral(GLESMacroDataType, type).c_str(),
                 pixels);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::CompressedTexImage2D(const string &label, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) const {
    if (enableVerboseOutput) {      /// mix
        LogDebug("glCompressedTexImage2D(target = %s, level = %d, internalformat = %d, width = %d, height = %d, border = %d imageSize = %d, data = %p)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 level,
                 internalformat,
                 width,
                 height,
                 border,
                 imageSize,
                 data);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::CompressedTexSubImage2D(const string &label, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) const {
    if (enableVerboseOutput) {      /// mix
        LogDebug("glCompressedTexSubImage2D(target = %s, level = %d, xoffset = %d, yoffset = %d, width = %d, height = %d, format = %d imageSize = %d, data = %p)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 level,
                 xoffset,
                 yoffset,
                 width,
                 height,
                 format,
                 imageSize,
                 data);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::ActiveTexture(const string &label, GLenum &texture) const {
    /**
     * Errors
     *
     * GL_INVALID_ENUM is generated if texture is not one of GL_TEXTUREi,
     * where i ranges from 0 to  (GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 1).
     *
     */
    glActiveTexture(texture);
    if (enableVerboseOutput) {
        LogDebug("glActiveTexture(%s: %s)", label.c_str(), toLFXOpenGLESLiteral(TextureUnit, texture).c_str());
        // check_error
    }
    return *this;
}

// todo: glTrue转换成字符串
const LFXOpenGLES &LFXOpenGLES::IsTexture(const string &label, GLuint texture, GLboolean &isTexture) const {
    isTexture = glIsTexture(texture);
    if (enableVerboseOutput) {
        LogDebug("glIsTexture(%s: %d) -> %d", label.c_str(), texture, isTexture);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::DeleteTextures(const string &label, GLsizei n, const GLuint *textures) const {
    if (enableVerboseOutput) {      /// mix
        LogDebug("glDeleteTextures(n = %d, textures = %p) -> %d", n, textures, *textures);
    }
    glDeleteTextures(n, textures);
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::CopyTexImage2D(const string &label, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) const {
    if (enableVerboseOutput) {      /// mix
        LogDebug("glCopyTexImage2D(target = %s, level = %d, internalformat = %d, x = %d, y = %d, width = %d, height = %d, border = %d)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 level,
                 internalformat,
                 x,
                 y,
                 width,
                 height,
                 border);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::CopyTexSubImage2D(const string &label, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) const {
    if (enableVerboseOutput) {      /// mix
        LogDebug("glCopyTexSubImage2D(target = %s, level = %d, xoffset = %d, yoffset = %d, x = %d, y = %d, width = %d, height = %d)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 level,
                 xoffset,
                 yoffset,
                 x,
                 y,
                 width,
                 height);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GenerateMipmap(const string &label, GLenum target) const {
    if (enableVerboseOutput) {      /// mix
        LogDebug("glGenerateMipmap(target = %s)", toLFXOpenGLESLiteral(TextureTarget, target).c_str());
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GenBuffers(const std::string &label, GLsizei n, GLuint *buffers) {
    /**
     * GL_INVALID_VALUE is generated if n is negative.
     */
    if (enableVerboseOutput) {      /// mix
        LogDebug("glGenBuffers(n = %d, buffers = %p)",
                 n,
                 buffers);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::BindBuffer(const string &label, GLenum target, GLuint buffer) const {
    if (enableVerboseOutput) {      /// mix
        LogDebug("glBindBuffer(target = %s, buffer = %d)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 buffer);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::BufferData(const string &label, GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage) {
    if (enableVerboseOutput) {      /// mix
        LogDebug("glufferData(target = %s, size = %ld, data = %p, usage = %d)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 size,
                 data,
                 usage);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::BufferSubData(const string &label, GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data) const {
    if (enableVerboseOutput) {      /// mix
        LogDebug("gl:BufferSubData(target = %s, offset = %ld, size = %ld, data = %p)",
                 toLFXOpenGLESLiteral(TextureTarget, target).c_str(),
                 offset,
                 size,
                 data);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::DeleteBuffers(ConstStringRefLabel, GLsizei n, const GLuint *buffers) const {
    
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::IsBuffer(const string &label, GLuint buffer) const {
    if (enableVerboseOutput) {      /// mix
        LogDebug("glIsBuffer(buffer = %d)", buffer);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetBufferParameteriv(const string &label, GLenum target, GLenum pname, GLint *params) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::BindRenderbuffer(const string &label, GLenum target, GLuint renderbuffer) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::DeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GenRenderbuffers(GLsizei n, GLuint *renderbuffers) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::RenderbufferStorage(const string &label, GLenum target, GLenum internalformat, GLsizei width, GLsizei height) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetRenderbufferParameteriv(const string &label, GLenum target, GLenum pname, GLint *params) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::IsRenderbuffer(const string &label, GLuint renderbuffer) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GenFramebuffers(const string &label, GLsizei n, GLuint *framebuffers) const {
    if (n <= 0) {
        LogDebug("n <= 0");
        return *this;
    }
    glGenFramebuffers(n, framebuffers);
    LogDebug("glGenFramebuffers(count = %d, framebuffers = %p) -> ", n, framebuffers);
    //        if (GPUDevice::isDebug())
    //        {
    //            char names[n * 2] = {0};
    //            sprintf(names, "glGenFramebuffers(count = %d, framebuffers = %p) -> ", n, framebuffers);
    //            for (int i = 0; i < n; ++i)
    //            {
    //                sprintf(names, "%d ", framebuffers[i]);
    //            }
    //            sprintf(names, "");
    //            LogDebug("%s", names);
    //        }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::BindFramebuffer(const string &label, GLenum target, GLuint framebuffer) const {
    /**
     * GL_DRAW_FRAMEBUFFER, GL_READ_FRAMEBUFFER or GL_FRAMEBUFFER.
     */
    glBindFramebuffer(target, framebuffer);
    LogDebug("glBindFramebuffer(target = %s: %s, framebuffer = %d)",
             toLFXOpenGLESLiteral(FramebufferObject, target).c_str(),
             label.c_str(),
             framebuffer);
    
#if GL_EXT_debug_label
    glLabelObjectEXT(GL_FRAMEBUFFER, framebuffer, 0, label.c_str());
    /// 在glGenFramebuffers时只调用一次是无效的？只有下面这样每次都调用才有效？为什么glCreateProgram只调用一次有效呢？
    /**
     * 苹果文档的示例使用是bind之后才打标注
     * https://developer.apple.com/library/content/documentation/3DDrawing/Conceptual/OpenGLES_ProgrammingGuide/Performance/Performance.html
     * glGenVertexArraysOES(1, &_spaceshipMesh);
     * glBindVertexArrayOES(_spaceshipMesh);
     * glLabelObjectEXT(GL_VERTEX_ARRAY_OBJECT_EXT, _spaceshipMesh, 0, "Spaceship");
     */
#endif
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::CheckFramebufferStatus(const string &label, GLenum target, GLenum &status) const {
    status = glCheckFramebufferStatus(target);
    LogDebug("glCheckFramebufferStatus(%s) -> %s",
             toLFXOpenGLESLiteral(FramebufferObject, target).c_str(),
             toLFXOpenGLESLiteral(FramebufferObject, status).c_str());
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::DeleteFramebuffers(GLsizei n, const GLuint *framebuffers) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::FramebufferRenderbuffer(const string &label, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::FramebufferTexture2D(const string &label, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) const {
    //#if GL_EXT_debug_label
    //        /// GL_TEXTURE 正常工作
    //        static char kOutputTexture[] = "outputTexture";
    //        glBindTexture(GL_TEXTURE, texture->getHandle());
    //        glLabelObjectEXT(GL_TEXTURE, texture->getHandle(), 0, kOutputTexture);
    //#endif
    glFramebufferTexture2D(target, attachment, textarget, texture, level);
    LogDebug(
             "glFramebufferTexture2D(target = %s: %s, attachment = %s, texture target = %s, texture = %d, level = %d)",
             toLFXOpenGLESLiteral(FramebufferObject, target).c_str(),
             label.c_str(),
             toLFXOpenGLESLiteral(FramebufferObject, attachment).c_str(),
             toLFXOpenGLESLiteral(TextureTarget, textarget).c_str(),
             texture,
             level);
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetFramebufferAttachmentParameteriv(const string &label, GLenum target, GLenum attachment, GLenum pname, GLint *params) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::IsFramebuffer(const string &label, GLuint framebuffer) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::Viewport(GLint x, GLint y, GLsizei width, GLsizei height) const {
    glViewport(x, y, width, height);
    LogDebug("glViewport(x = %d, y = %d, width = %d, height = %d)", x, y, width, height);
    return *this;
}

#pragma mark Shader

const LFXOpenGLES &LFXOpenGLES::CreateShader(const string &label, GLenum shaderType, GLuint &shader) const {
    //    shader = glCreateShader(shaderType);
    if (enableVerboseOutput) {
        LogDebug("glCreateShader(%s) -> %s: %d", toLFXOpenGLESLiteral(LFXOpenGLESShaderType, shaderType).c_str(), label.c_str(), shader);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::ShaderSource(const string &label, GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length) const {
    //    glShaderSource(shader, count, string, length);
    if (enableVerboseOutput) {
        LogDebug("glShaderSource(shader = %s: %d, count = %d, string = %p, length = %p)", label.c_str(), shader, count, string, length);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::CompileShader(const string &label, GLuint shader) const {
    //    glCompileShader(shader);
    if (enableVerboseOutput) {
        LogDebug("glCompileShader(shader = %s: %d)", label.c_str(), shader);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetShaderiv(const string &label, GLuint shader, GLenum pname, GLint *params) const {
    //    glGetShaderiv(shader, pname, params);
    if (enableVerboseOutput) {
        LogDebug("glGetShaderiv(shader = %s: %d, pname = %s, params = %p) -> %s", label.c_str(), shader, toLFXOpenGLESLiteral(LFXOpenGLESParamsName, pname).c_str(), params, toLFXOpenGLESLiteral(LFXOpenGLESBoolean, *params).c_str());
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetShaderInfoLog(const string &label, GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *log) const {
    //    glGetShaderInfoLog(shader, bufsize, NULL, log);
    if (enableVerboseOutput) {
        LogDebug("glGetShaderInfoLog(shader = %s: %d, bufsize = %d, length = %p, log = %p)", label.c_str(), shader, bufsize, length, (void *) log);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::DeleteShader(const string &label, GLuint shader) const {
    //    glDeleteShader(shader);
    if (enableVerboseOutput) {
        LogDebug("glDeleteShader(shader = %s: %d)", label.c_str(), shader);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::IsShader(const string &label, GLuint shader, GLboolean &isShader) const {
    //    isShader = glIsShader(shader);
    if (enableVerboseOutput) {
        LogDebug("glIsShader(shader = %s: %d) -> %s", label.c_str(), shader, toLFXOpenGLESLiteral(LFXOpenGLESBoolean, isShader).c_str());
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::ShaderBinary(GLsizei n, const GLuint *shaders, GLenum binaryformat, const GLvoid *binary, GLsizei length) const {
    //    glShaderBinary(n, shaders, binaryformat, binary, length);
    if (enableVerboseOutput) {
        LogDebug("glShaderBinary(n = %d, shaders = %p, binaryformat = %s, binary = %p, length = %d)", n, shaders, toLFXOpenGLESLiteral(LFXOpenGLESParamsName, binaryformat).c_str(), binary, length)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::ReleaseShaderCompiler(void) const {
    //    glReleaseShaderCompiler();
    if (enableVerboseOutput) {
        LogDebug("glReleaseShaderCompiler()")
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetShaderSource(const string &label, GLuint shader, GLsizei bufsize, GLsizei *length, GLchar *source) const {
    //    glGetShaderSource(shader, bufsize, length, source);
    if (enableVerboseOutput) {
        LogDebug("glGetShaderSource(shader = %s: %d, bufsize = %d, length = %p, source = %s)", label.c_str(), shader, bufsize, length, source)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetShaderPrecisionFormat(const string &label, GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) const {
    glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
    if (enableVerboseOutput) {
        //        LogDebug("glGetShaderPrecisionFormat(shadertype = %s, precisiontype = %s, range= %p, precision = %d)")
    }
    return *this;
}

#pragma mark - Stencil

const LFXOpenGLES &LFXOpenGLES::
StencilOpSeparate(const string &label, GLenum face, GLenum fail, GLenum zfail, GLenum zpass) const {
    //glStencilOpSeparate(face, fail, zfail, zpass);
    if (enableVerboseOutput) {
        LogDebug("glStencilOpSeparate(face = %d, fail = %d, zfail= %d, zpass = %d)", face, fail, zfail, zpass);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
StencilOp(const string &label, GLenum fail, GLenum zfail, GLenum zpass) const {
    //glStencilOp(fail, zfail, zpass);
    if (enableVerboseOutput) {
        LogDebug("glStencilOp(fail = %d, zfail= %d, zpass = %d)", fail, zfail, zpass);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
StencilMaskSeparate(const string &label, GLenum face, GLuint mask) const {
    //glStencilMaskSeparate(face, mask);
    if (enableVerboseOutput) {
        LogDebug("glStencilMaskSeparate(face = %d, mask= %d)", face, mask);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
StencilMask(const string &label, GLuint mask) const {
    //glStencilMask(mask);
    if (enableVerboseOutput) {
        LogDebug("glStencilMask(mask= %d)", mask);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
StencilFuncSeparate(const string &label, GLenum face, GLenum func, GLint ref, GLuint mask) const {
    //glStencilFuncSeparate(face, func, ref, mask);
    if (enableVerboseOutput) {
        LogDebug("glStencilFuncSeparate(face = %d, func = %d, ref = %d, mask= %d)", face, func, ref, mask);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
StencilFunc(const string &label, GLenum func, GLint ref, GLuint mask) const {
    glStencilFunc(func, ref, mask);
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::Scissor(GLint x, GLint y, GLsizei width, GLsizei height) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::SampleCoverage(GLclampf value, GLboolean invert) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::PolygonOffset(GLfloat factor, GLfloat units) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::PixelStorei(const string &label, GLenum pname, GLint param) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::LineWidth(GLfloat width) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::IsEnabled(const string &label, GLenum cap) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::Hint(const string &label, GLenum target, GLenum mode) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetString(const string &label, GLenum name, const GLubyte *byte) const {
    byte = glGetString(name);
    LogTrace("glGetString(%s) -> %s", toLFXOpenGLESLiteral(GLESMacroDataType, name).c_str(), byte);
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetIntegerv(const string &label, GLenum pname, GLint *params) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetFloatv(const string &label, GLenum pname, GLfloat *params) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetError(GLenum &error) const {
    error = glGetError();
    LogInfo("glGetError() -> %s", toLFXOpenGLESLiteral(GLESMacroDataType, error).c_str());
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::GetBooleanv(const string &label, GLenum pname, GLboolean *params) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::FrontFace(const string &label, GLenum mode) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::Flush(void) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::Finish(void) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::Enable(GLenum cap) const {
    glEnable(cap);
    LogDebug("glEnable(%s)", toLFXOpenGLESLiteral(TextureTarget, cap).c_str());
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::DrawElements(const string &label, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::DrawArrays(GLenum mode, GLint first, GLsizei count) const {
    glDrawArrays(mode, first, count);
    LogDebug("glDrawArrays(%s, first = %d, count = %d)", toLFXOpenGLESLiteral(BeginMode, mode).c_str(), first, count);
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::Disable(const string &label, GLenum cap) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::DepthRangef(GLclampf zNear, GLclampf zFar) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::DepthMask(GLboolean flag) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::DepthFunc(const string &label, GLenum func) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::CullFace(const string &label, GLenum mode) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::ClearStencil(GLint s) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::ClearDepthf(GLclampf depth) const {
    return *this;
}

const LFXOpenGLES &
LFXOpenGLES::ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) const {
    glClearColor(red, green, blue, alpha);
    if (enableVerboseOutput) {
        LogDebug("glClearColor(r = %f, g = %f, b = %f, a = %f)", red, green, blue, alpha);
    }
    return *this;
}

#pragma mark Clear

// todo: 改日志，宏
const LFXOpenGLES &
LFXOpenGLES::Clear(GLbitfield mask) const {
    glClear(mask);
    if (enableVerboseOutput) {
        LogDebug("glClear(%s)", toLFXOpenGLESLiteral(GLESMacroDataType, mask).c_str());
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::BlendFuncSeparate(const string &label, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::BlendFunc(GLenum sfactor, GLenum dfactor) const {
    glBlendFunc(sfactor, dfactor);
    LogDebug("glBlendFunc(sfactor = %s, dfactor = %s)",
             toLFXOpenGLESLiteral(Blend, sfactor).c_str(),
             toLFXOpenGLESLiteral(Blend, dfactor).c_str());
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::BlendEquationSeparate(const string &label, GLenum modeRGB, GLenum modeAlpha) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::BlendEquation(const string &label, GLenum mode) const {
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) const {
    return *this;
}

#pragma mark Program

const LFXOpenGLES &LFXOpenGLES::
DisableVertexAttribArray(const string &label, GLuint index) const {
    glDisableVertexAttribArray(index);
    if (enableVerboseOutput) {
        LogDebug("glDisableVertexAttribArray(%s: %d)", label.c_str(), index)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
EnableVertexAttribArray(const string &label, GLuint location) const {
    glEnableVertexAttribArray(location); /// need active program? Otherwise cause >GLDRendererMetal command buffer completion error: Error Domain=MTLCommandBufferErrorDomain Code=2 "Caused GPU Hang Error (IOAF code 3)" UserInfo={NSLocalizedDescription=Caused GPU Hang Error (IOAF code 3)}
    if (enableVerboseOutput) {
        LogInfo("glEnableVertexAttribArray(%s: %d)", label.c_str(), location);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
IsProgram(const string &label, GLuint program, GLboolean &isProgram) const {
    isProgram = glIsProgram(program);
    if (enableVerboseOutput) {
        //        LogDebug("glIsProgram(%s: %d) -> %s", label.c_str(), program, toLFXOpenGLESLiteral(LFXOpenGLESBoolean, isProgram))
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetVertexAttribPointerv(const string &label, GLuint index, GLenum pname, GLvoid **pointer) const {
    glGetVertexAttribPointerv(index, pname, pointer);
    if (enableVerboseOutput) {
        //        LogDebug("glGetVertexAttribPointerv(index = %d, pname = %s, pointer = %p)", label.c_str(), toLFXOpenGLESLiteral(LFXOpenGLESBoolean, isProgram))
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetVertexAttribiv(const string &label, GLuint index, GLenum pname, GLint *params) const {
    glGetVertexAttribiv(index, pname, params);
    if (enableVerboseOutput) {
        LogDebug("glGetVertexAttribiv(index, pname, params)");
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetVertexAttribfv(const string &label, GLuint index, GLenum pname, GLfloat *params) const {
    glGetVertexAttribfv(index, pname, params);
    if (enableVerboseOutput) {
        LogDebug("glGetVertexAttribfv(index, pname, params)")
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetUniformLocation(const string &label, GLuint program, const GLchar *name, int location) const {
    //    location = glGetUniformLocation(program, name);
    if (enableVerboseOutput) {
        LogDebug("glGetUniformLocation(%s: %d, %s) -> %d", label.c_str(), program, name, location);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetUniformiv(const string &label, GLuint program, GLint location, GLint *params) const {
    //    glGetUniformiv(program, location, params);
    if (enableVerboseOutput) {
        LogDebug("glGetUniformiv(%s: %d, location = %d, params = %p)", label.c_str(), program, location, params)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetUniformfv(const string &label, GLuint program, GLint location, GLfloat *params) const {
    //    glGetUniformfv(program, location, params);
    if (enableVerboseOutput) {
        LogDebug("glGetUniformfv(%s: %d, location = %d, params = %p)", label.c_str(), program, location, params)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
DetachShader(const string &label, GLuint program, GLuint shader) const {
    /**
     * 据资料称，苹果的驱动会将shader对象缓存到哈希表中，之后若编译相同shader，则立即从该哈希表中取出，节约时间。这里调用`glDeleteShader`不知是否影响该机制，有待实测。
     */
    glDetachShader(program, shader);
    if (enableVerboseOutput) {
        LogDebug("glDetachShader(program = %d, shader = %d)", program, shader);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
BindAttribLocation(const string &label, GLuint program, GLuint index, const GLchar *name) const {
    /**
     * glBindAttribLocation在glLinkProgram之前调用
     */
    glBindAttribLocation(program, index, name);
    if (enableVerboseOutput) {
        LogDebug("glBindAttribLocation(program = %s: %d, index = %d, name = %s)", label.c_str(), program, index, name)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
VertexAttribPointer(const string &label, GLuint location, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *ptr) const {
    glVertexAttribPointer(location, size, type, normalized, stride, ptr);
    if (enableVerboseOutput) {
        LogDebug("glVertexAttribPointer(%s: %d, size = %d, type = %s, normalized = %s, stride = %d, ptr = %p)",
                 label.c_str(),
                 location,
                 size,
                 toLFXOpenGLESLiteral(GLESMacroDataType, type).c_str(),
                 toLFXOpenGLESLiteral(LFXOpenGLESBoolean, normalized).c_str(),
                 stride,
                 ptr);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
VertexAttrib4fv(const string &label, GLuint indx, const GLfloat *values) const {
    //    glVertexAttrib4fv(indx, values);
    if (enableVerboseOutput) {
        LogDebug("glVertexAttrib4fv(%s: %d, values = %p)", label.c_str(), indx, values)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
VertexAttrib4f(const string &label, GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const {
    //    glVertexAttrib4f(indx, x, y, z, w);
    if (enableVerboseOutput) {
        LogDebug("glVertexAttrib4f(%s: %d, x, y, z, w)", label.c_str(), indx, x, y, z, w)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
VertexAttrib3fv(const string &label, GLuint indx, const GLfloat *values) const {
    //    glVertexAttrib3fv(indx, values);
    if (enableVerboseOutput) {
        LogDebug("glVertexAttrib3fv(%s: %d, values = %p)", label.c_str(), indx, values)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
VertexAttrib3f(const string &label, GLuint indx, GLfloat x, GLfloat y, GLfloat z) const {
    //    glVertexAttrib3f(indx, x, y, z);
    if (enableVerboseOutput) {
        LogDebug("glVertexAttrib3f(%s: %d, x, y, z)", label.c_str(), indx, x, y, z)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
VertexAttrib2fv(const string &label, GLuint indx, const GLfloat *values) const {
    //    glVertexAttrib2fv(indx, values);
    if (enableVerboseOutput) {
        LogDebug("glVertexAttrib2fv(%s: %d, values = %p)", label.c_str(), indx, values)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
VertexAttrib2f(const string &label, GLuint indx, GLfloat x, GLfloat y) const {
    //    glVertexAttrib2f(indx, x, y);
    if (enableVerboseOutput) {
        LogDebug("glVertexAttrib2f(%s: %d, x, y)", label.c_str(), indx, x, y)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
VertexAttrib1fv(const string &label, GLuint indx, const GLfloat *values) const {
    //    glVertexAttrib1fv(indx, values);
    if (enableVerboseOutput) {
        LogDebug("glVertexAttrib1fv(%s: %d, values = %p)", label.c_str(), indx, values)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
VertexAttrib1f(const string &label, GLuint indx, GLfloat x) const {
    //    glVertexAttrib1f(indx, x);
    if (enableVerboseOutput) {
        LogDebug("glVertexAttrib1f(%s: %d, x)", label.c_str(), indx, x)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
UniformMatrix4fv(ConstStringRefLabel, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) const {
    //    glUniformMatrix4fv(location, count, transpose, value);
    if (enableVerboseOutput) {
        LogDebug("glUniformMatrix4fv(%s: %d, count = %d, transpose = %s, value = %p)", label.c_str(), location, count, toLFXOpenGLESLiteral(LFXOpenGLESBoolean, transpose).c_str(), value)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
UniformMatrix3fv(ConstStringRefLabel, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) const {
    //    glUniformMatrix3fv(location, count, transpose, value);
    if (enableVerboseOutput) {
        LogDebug("glUniformMatrix3fv(%s: %d, count = %d, transpose = %s, value = %p)", label.c_str(), location, count, toLFXOpenGLESLiteral(LFXOpenGLESBoolean, transpose).c_str(), value)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
UniformMatrix2fv(ConstStringRefLabel, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) const {
    //    glUniformMatrix2fv(location, count, transpose, value);
    if (enableVerboseOutput) {
        LogDebug("glUniformMatrix2fv(%s: %d, count = %d, transpose = %s, value = %p)", label.c_str(), location, count, toLFXOpenGLESLiteral(LFXOpenGLESBoolean, transpose).c_str(), value)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform4iv(ConstStringRefLabel, GLint location, GLsizei count, const GLint *v) const {
    //    glUniform4iv(location, count, v);
    if (enableVerboseOutput) {
        LogDebug("glUniform4iv(%s: %d, count = %d, v = %p)", label.c_str(), location, count, v)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform4i(ConstStringRefLabel, GLint location, GLint x, GLint y, GLint z, GLint w) const {
    //    glUniform4i(location, x, y, z, w);
    if (enableVerboseOutput) {
        LogDebug("glUniform4i(%s: %d, x = %d, y = %d, z = %d, w = %d)", label.c_str(), location, x, y, z, w);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform4fv(ConstStringRefLabel, GLint location, GLsizei count, const GLfloat *v) const {
    //    glUniform4fv(location, count, v);
    if (enableVerboseOutput) {
        LogDebug("glUniform4fv(%s: %d, count = %d, v = %p)", label.c_str(), location, count, v)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform4f(ConstStringRefLabel, GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) const {
    //    glUniform4f(location, x, y, z, w);
    if (enableVerboseOutput) {
        LogDebug("glUniform4f(%s: %d, x = %f, y = %f, z = %f, w = %f)", label.c_str(), location, x, y, z, w)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform3iv(ConstStringRefLabel, GLint location, GLsizei count, const GLint *v) const {
    //    glUniform3iv(location, count, v);
    if (enableVerboseOutput) {
        LogDebug("glUniform3iv(%s: %d, count = %d, v = %p)", label.c_str(), location, count, v)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform3i(ConstStringRefLabel, GLint location, GLint x, GLint y, GLint z) const {
    //    glUniform3i(location, x, y, z);
    if (enableVerboseOutput) {
        LogDebug("glUniform3i(%s: %d, x = %d, y = %d, z = %d)", label.c_str(), location, x, y, z);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform3fv(ConstStringRefLabel, GLint location, GLsizei count, const GLfloat *v) const {
    //    glUniform3fv(location, count, v);
    if (enableVerboseOutput) {
        LogDebug("glUniform3fv(%s: %d, count = %d, v = %p)", label.c_str(), location, count, v)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform3f(ConstStringRefLabel, GLint location, GLfloat x, GLfloat y, GLfloat z) const {
    //    glUniform3f(location, x, y, z);
    if (enableVerboseOutput) {
        LogDebug("glUniform3f(%s: %d, x = %f, y = %f, z = %f)", label.c_str(), location, x, y, z)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform2iv(ConstStringRefLabel, GLint location, GLsizei count, const GLint *v) const {
    //    glUniform2iv(location, count, v);
    if (enableVerboseOutput) {
        LogDebug("glUniform2iv(%s: %d, count = %d, v = %p)", label.c_str(), location, count, v)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform2i(ConstStringRefLabel, GLint location, GLint x, GLint y) const {
    //    glUniform2i(location, x, y);
    if (enableVerboseOutput) {
        LogDebug("glUniform2i(%s: %d, x = %d, y = %d)", label.c_str(), location, x, y);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform2fv(ConstStringRefLabel, GLint location, GLsizei count, const GLfloat *v) const {
    //    glUniform2fv(location, count, v);
    if (enableVerboseOutput) {
        LogDebug("glUniform2fv(%s: %d, count = %d, v = %p)", label.c_str(), location, count, v)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform2f(ConstStringRefLabel, GLint location, GLfloat x, GLfloat y) const {
    //    glUniform2f(location, x, y);
    if (enableVerboseOutput) {
        LogDebug("glUniform2f(%s: %d, x = %f, y = %f)", label.c_str(), location, x, y)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform1iv(const string &label, GLint location, GLsizei count, const GLint *v) const {
    //    glUniform1iv(location, count, v);
    if (enableVerboseOutput) {
        LogDebug("glUniform1iv(%s: %d, %d)", label.c_str(), location, count, v);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform1i(ConstStringRefLabel, GLint location, GLint value) const {
    //    glUniform1i(location, value);
    if (enableVerboseOutput) {
        LogDebug("glUniform1i(%s: %d, %d)", label.c_str(), location, value);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform1fv(ConstStringRefLabel, GLint location, GLsizei count, const GLfloat *v) const {
    //    glUniform1fv(location, count, v);
    if (enableVerboseOutput) {
        LogDebug("glUniform1fv(%s: %d, count = %d, v = %p)", label.c_str(), location, count, v)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
Uniform1f(ConstStringRefLabel, GLint location, GLfloat x) const {
    //    glUniform1f(location, x);
    if (enableVerboseOutput) {
        LogDebug("glUniform1f(%s: %d, %f)", label.c_str(), location, x)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetProgramInfoLog(const string &label, GLuint program, GLsizei bufsize, GLsizei *length, GLchar *infolog) const {
    glGetProgramInfoLog(program, bufsize, length, infolog);
    if (enableVerboseOutput) {
        LogDebug("glGetProgramInfoLog(program, bufsize, length, infolog)")
    }
    return *this;
}

/// todo: 返回日志长度
const LFXOpenGLES &LFXOpenGLES::
GetProgramiv(const string &label, GLuint program, GLenum pname, GLint *params) const {
    glGetProgramiv(program, pname, params);
    if (enableVerboseOutput) {
        LogDebug("glGetProgramiv(%s: %d, pname = %s, params = %p) -> %s",
                 label.c_str(),
                 program,
                 toLFXOpenGLESLiteral(LFXOpenGLESParamsName, pname).c_str(),
                 params,
                 toLFXOpenGLESLiteral(LFXOpenGLESBoolean, *params).c_str());
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetAttribLocation(const string &label, GLuint program, const GLchar *name, int &location) const {
    location = glGetAttribLocation(program, name);
    if (enableVerboseOutput) {
        LogDebug("glGetAttribLocation(%s: %d, %s) -> %d", label.c_str(), program, name, location);
        if (location < 0) {
            /// something goes wrong.
            LogDebug("not found argument(%s)", name);
        }
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetAttachedShaders(const string &label, GLuint program, GLsizei maxcount, GLsizei *count, GLuint *shaders) const {
    glGetAttachedShaders(program, maxcount, count, shaders);
    if (enableVerboseOutput) {
        LogDebug("glGetAttachedShaders(program = %s: %d, maxcount = %d, count = %p, shaders = %p)", label.c_str(), program, maxcount, count, shaders)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetActiveUniform(const string &label, GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) const {
    if (enableVerboseOutput) {
        LogDebug("")
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
GetActiveAttrib(const string &label, GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) const {
    if (enableVerboseOutput) {
        LogDebug("")
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
DeleteProgram(const string &label, GLuint program) const {
    glDeleteProgram(program);
    if (enableVerboseOutput) {
        LogDebug("glDeleteProgram(%s: %d)", label.c_str(), program);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
ValidateProgram(const string &label, GLuint program) const {
    glValidateProgram(program);
    if (enableVerboseOutput) {
        LogDebug("glValidateProgram(%s: %d)", label.c_str(), program)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
UseProgram(const string &label, GLuint program) const {
    /*
     While a program object is in use, applications are free to modify attached shader objects, compile attached shader objects, attach additional shader objects, and detach or delete shader objects. None of these operations will affect the executables that are part of the current state. However, relinking the program object that is currently in use will install the program object as part of the current rendering state if the link operation was successful (see glLinkProgram ). If the program object currently in use is relinked unsuccessfully, its link status will be set to GL_FALSE, but the executables and associated state will remain part of the current state until a subsequent call to glUseProgram removes it from use. After it is removed from use, it cannot be made part of current state until it has been successfully relinked.
     */
    glUseProgram(program);
    if (enableVerboseOutput) {
        LogDebug("glUseProgram(%s: %d)", label.c_str(), program)
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
LinkProgram(const string &label, GLuint program) const {
    glLinkProgram(program);
    if (enableVerboseOutput) {
        LogDebug("glLinkProgram(%s: %d)", label.c_str(), program);
    }
    return *this;
}

/// todo: 日志加上shader的label
const LFXOpenGLES &LFXOpenGLES::
AttachShader(const string &label, GLuint program, GLuint shader) const {
    glAttachShader(program, shader);
    if (enableVerboseOutput) {
        LogDebug("glAttachShader(program = %s: %d, shader = %d)", label.c_str(), program, shader);
    }
    return *this;
}

const LFXOpenGLES &LFXOpenGLES::
CreateProgram(ConstStringRefLabel, GLuint &program) const {
    program = glCreateProgram();
    if (enableVerboseOutput) {
        LogDebug("glCreateProgram() -> %s: %d", label.c_str(), program);
#ifdef __APPLE__
        glLabelObjectEXT(GL_PROGRAM_OBJECT_EXT, program, 0, label.c_str());
#endif
    }
    return *this;
}

const LFXOpenGLES gl = LFXOpenGLES();
