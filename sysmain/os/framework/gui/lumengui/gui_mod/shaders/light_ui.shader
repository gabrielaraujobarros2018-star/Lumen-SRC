void main() {
    vec4 color = texture2D(tex, uv);
    color.rgb *= 1.08;
    gl_FragColor = color;
}