function TouchPressure()
sub GetTouch(byref status, byref x, byref y, byref dx, byref dy)
sub GetMultiTouch(byref status, byref x, byref y, byref fingers, byref dist, byref theta)
sub GetTouchFinger(finger, byref x, byref y, byref pressure)
function NumFingers()
sub GetAccel(accel_num, ByRef x, ByRef y, ByRef z)
function AccelName$(accel_num)
function NumAccels()
sub GetGyro(gyro_num, ByRef x, ByRef y, ByRef z)
function GyroName$(gyro_num)
function NumGyros()
