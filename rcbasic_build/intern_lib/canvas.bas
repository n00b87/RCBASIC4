function OpenCanvas( w, h, viewport_x, viewport_y, viewport_w, viewport_h, mode)
Sub CloseCanvas(c_num)
Sub SetCanvas3D(c_num, flag)
sub SetCanvasVisible(c_num, flag)
function CanvasIsVisible(c_num)
sub SetCanvasViewport(cnum, x, y, w, h)
sub GetCanvasViewport(c_num, byref x, byref y, byref w, byref h)
sub Canvas(c_num)
sub SetCanvasOffset(c_num, x, y)
sub GetCanvasOffset(c_num, byref x, byref y)
sub GetCanvasSize(c_num, byref w, byref h)
sub ClearCanvas()
sub SetCanvasAlpha(c_num, a)
function CanvasAlpha(c_num)
function SetCanvasColorMod(c_num, c)
function CanvasColorMod(c_num)
sub CopyCanvas(src, x, y, w, h, dst, dx, dy)
sub CloneCanvas(src, dst)
sub SetCanvasZ(c_num, z)
function CanvasZ(c_num)
function CanvasClip(x, y, w, h)
function ActiveCanvas()
