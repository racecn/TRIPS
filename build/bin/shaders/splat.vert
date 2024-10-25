// shaders/splat.vert
#version 450 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in float size;

uniform mat4 viewProj;

out vec3 fragColor;
out float fragSize;

void main() {
    gl_Position = viewProj * vec4(position, 1.0);
    fragColor = color;
    fragSize = size;
}

// shaders/splat.frag
#version 450 core

in vec3 fragColor;
in float fragSize;

layout(location = 0) out vec4 outColor;

void main() {
    vec2 coord = gl_FragCoord.xy;
    float dist = length(coord - gl_FragCoord.xy);
    float alpha = smoothstep(fragSize, 0.0, dist);
    outColor = vec4(fragColor, alpha);
}