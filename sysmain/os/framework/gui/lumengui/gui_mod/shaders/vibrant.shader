uniform float saturation;

void main() {
    vec4 color = texture2D(tex, uv);
    float gray = dot(color.rgb, vec3(0.3,0.59,0.11));
    color.rgb = mix(vec3(gray), color.rgb, saturation);
    gl_FragColor = color;
}