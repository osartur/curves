attribute vec4 position;
attribute vec4 color;
varying vec4 fcolor;

void main()
{
    gl_Position = position;
    fcolor = color;
}
