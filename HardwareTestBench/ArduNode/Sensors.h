#define FrontTyrePressureThreshold 20
#define RearTyrePressureThreshold 24

#define TyreTemperatureThreshold 110

#define BrakeTemperatureThreshold 700
#define BrakeWearThreshold 200


int readSensorDataTyre(int a)
{
    int n = 0;
    
    switch (a)
    {
        case 1: n = ((rand() % 50) > FrontTyrePressureThreshold) ? 0 : 1; break;
        case 2: n = ((rand() % 50) > FrontTyrePressureThreshold) ? 0 : 1; break;
        case 3: n = ((rand() % 50) > RearTyrePressureThreshold) ? 0 : 1; break;
        case 4: n = ((rand() % 50) > RearTyrePressureThreshold) ? 0 : 1; break;
        case 5: n = ((rand() % 200) > TyreTemperatureThreshold) ? 0 : 1; break;
        case 6: n = ((rand() % 200) > TyreTemperatureThreshold) ? 0 : 1; break;
        case 7: n = ((rand() % 200) > TyreTemperatureThreshold) ? 0 : 1; break;
        case 8: n = ((rand() % 200) > TyreTemperatureThreshold) ? 0 : 1; break;
    }
    
    return n;
}

//Function to read brake data 
int readSensorDataBrake(int a)
{

    int n = 0;
    
    switch (a)
    {
        case 1: n = ((rand() % 1000) > BrakeTemperatureThreshold) ? 0 : 1; break;
        case 2: n = ((rand() % 1000) > BrakeTemperatureThreshold) ? 0 : 1; break;
        case 3: n = ((rand() % 1000) > BrakeTemperatureThreshold) ? 0 : 1; break;
        case 4: n = ((rand() % 1000) > BrakeTemperatureThreshold) ? 0 : 1; break;
        case 5: n = ((rand() % 300) > BrakeWearThreshold) ? 0 : 1; break;
        case 6: n = ((rand() % 300) > BrakeWearThreshold) ? 0 : 1; break;
        case 7: n = ((rand() % 300) > BrakeWearThreshold) ? 0 : 1; break;
        case 8: n = ((rand() % 300) > BrakeWearThreshold) ? 0 : 1; break;
    }
    
    return n;
}

int readSensorDataToggles(int a)
{
    int n = rand() % 2;
    return n;
}
