void main() {
    vec4 color = texture2D(tex, uv);
    float shadow = smoothstep(0.4, 1.0, uv.y);
    gl_FragColor = vec4(color.rgb * shadow, color.a);
}