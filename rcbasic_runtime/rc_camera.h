#ifndef RC_CAMERA_H_INCLUDED
#define RC_CAMERA_H_INCLUDED

void rc_setCameraPosition(double x, double y, double z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.setPosition(x, y, z);
}

void rc_getCameraPosition(double* x, double* y, double* z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    irr::f32 fx, fy, fz;

    rc_canvas[rc_active_canvas].camera.getPosition(fx, fy, fz);

    *x = fx;
    *y = fy;
    *z = fz;
}

void rc_translateCamera(double x, double y, double z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.translate(x, y, z);
}

void rc_translateCameraW(double x, double y, double z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.translateW(x, y, z);
}


void rc_setCameraRotation(double x, double y, double z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.setRotation(x, y, z);
}

void rc_getCameraRotation(double* x, double* y, double* z)
{
    if(rc_active_canvas <= 0 || rc_active_canvas >= rc_canvas.size())
        return;

    *x = rc_canvas[rc_active_canvas].camera.rx;
    *y = rc_canvas[rc_active_canvas].camera.ry;
    *z = rc_canvas[rc_active_canvas].camera.rz;

    //std::cout << "Get Rotation: " << x[0] << ", " << y[0] << ", " << z[0] << std::endl;
}

void rc_rotateCamera(double x, double y, double z)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.rotate(x, y, z);
}

void rc_setCameraFOV(double fov)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.camera->setFOV(fov);
}

double rc_getCameraFOV()
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return 0;

    return rc_canvas[rc_active_canvas].camera.camera->getFOV();
}

void rc_setCameraAspectRatio(double aspect)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.camera->setAspectRatio(aspect);
}

double rc_getCameraAspectRatio()
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return 0;

    return rc_canvas[rc_active_canvas].camera.camera->getAspectRatio();
}

void rc_setCameraFarValue(double zf)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.camera->setFarValue(zf);
}

double rc_getCameraFarValue()
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return 0;

    return rc_canvas[rc_active_canvas].camera.camera->getFarValue();
}

void rc_setCameraNearValue(double zn)
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

    rc_canvas[rc_active_canvas].camera.camera->setNearValue(zn);
}

double rc_getCameraNearValue()
{
    if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return 0;

    return rc_canvas[rc_active_canvas].camera.camera->getNearValue();
}

void rc_setProjectionMatrix(int proj_matrix, int proj_type)
{
	if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

	if(proj_matrix < 0 || proj_matrix >= rc_matrix.size())
		return;

	if(!rc_matrix[proj_matrix].active)
		return;

	irr::core::matrix4 irr_mat = rc_convertToIrrMatrix(proj_matrix);
	bool isOrtho = (proj_type == RC_PROJECTION_TYPE_ORTHOGRAPHIC);
	rc_canvas[rc_active_canvas].camera.camera->setProjectionMatrix(irr_mat, isOrtho);
}

void rc_getProjectionMatrix(int proj_matrix)
{
	if(!(rc_active_canvas > 0 && rc_active_canvas < rc_canvas.size()))
        return;

	if(proj_matrix < 0 || proj_matrix >= rc_matrix.size())
		return;

	if(!rc_matrix[proj_matrix].active)
		return;

	irr::core::matrix4 pmat = rc_canvas[rc_active_canvas].camera.camera->getProjectionMatrix();
	rc_convertFromIrrMatrix(pmat, proj_matrix);
}

#endif // RC_CAMERA_H_INCLUDED
