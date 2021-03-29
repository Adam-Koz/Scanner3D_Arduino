import bpy
import math
import serial 
import time

ser = serial.Serial('COM3', 115200)
time.sleep(3)
print("connected to: " + ser.portstr)

ser.write(b'start\n')



def recive():
    data = str(ser.readline())    

    print("")
    print(data)
    print("")
    
    dataSplit = data.split("#")
        
    B = dataSplit[0]  # distance from objects
    Dx = dataSplit[1] # degree of x servo
    Dy = dataSplit[2] # degree of y servo


    Dy = Dy[:-5]
    B = B[2:]

    b = float(B)
    DxF = float(Dx)
    DyF = float(Dy)

    DxF, DyF = DyF, DxF # swap varible

    sinLx = math.sin(math.radians(DxF)) 
    if sinLx == 6.123233995736766e-17:
        sinLx = round(sinLx)

    cosLx = math.cos(math.radians(DxF)) 
    if cosLx == 6.123233995736766e-17:
        cosLx = round(cosLx)

    cosLy = math.cos(math.radians(DyF))
    if cosLy == 6.123233995736766e-17:
        cosLy = round(cosLy)

    if sinLx<0:
        sinLx = -sinLx
        
    if cosLx<0:
        cosLx = -cosLx 


    X = b*cosLx
    Y = X*cosLy
    Z = b*sinLx
    bpy.ops.mesh.primitive_cube_add( location = (X, Y, Z)) 
    print("------------------------------------")
    print(X)
    print(Dx)
    print(DyF)
    print(cosLy)
    

x=0
while x<16110:
    recive()
    x+=1

ser.close()
