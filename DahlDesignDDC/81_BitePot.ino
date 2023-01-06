void brake(int analogPin, int switchNumber, int startValue, int endValue)
{
    int inputPin = analogPin;
    int pinValue = analogRead(inputPin);
    int N = switchNumber - 1;
    float normalized = 0;

    if (endValue > startValue)
    {
        endValue = endValue - clutchTopDeadzone;
        startValue = startValue + clutchBottomDeadzone;
        float gap = endValue - startValue;
        float normFactor = 1000 / gap;
        normalized = normFactor * (pinValue - startValue);
        if (normalized < 0)
        {
            normalized = 0;
        }
    }
    else if (endValue < startValue)
    {
        endValue = endValue + clutchTopDeadzone;
        startValue = startValue - clutchBottomDeadzone;
        float gap = startValue - endValue;
        float normFactor = 1000 / gap;
        normalized = normFactor * (startValue - pinValue);
        if (normalized < 0)
        {
            normalized = 0;
        }
    }

    total[N] = total[N] - readings[N][readIndex[N]];
    readings[N][readIndex[N]] = normalized;
    total[N] = total[N] + readings[N][readIndex[N]];

    readIndex[N]++;

    if (readIndex[N] > (reads - 1))
    {
        readIndex[N] = 0;
    }

    average[N] = total[N] / reads;
    if (average[N] > 1000)
    {
        average[N] = 1000;
    }

    //----------------SET AXIS----------------
    Joystick.setBrake(average[N]);
}

void throttle(int analogPin, int switchNumber, int startValue, int endValue)
{
    int inputPin = analogPin;
    int pinValue = analogRead(inputPin);
    int N = switchNumber - 1;
    float normalized = 0;

    if (endValue > startValue)
    {
        endValue = endValue - clutchTopDeadzone;
        startValue = startValue + clutchBottomDeadzone;
        float gap = endValue - startValue;
        float normFactor = 1000 / gap;
        normalized = normFactor * (pinValue - startValue);
        if (normalized < 0)
        {
            normalized = 0;
        }
    }
    else if (endValue < startValue)
    {
        endValue = endValue + clutchTopDeadzone;
        startValue = startValue - clutchBottomDeadzone;
        float gap = startValue - endValue;
        float normFactor = 1000 / gap;
        normalized = normFactor * (startValue - pinValue);
        if (normalized < 0)
        {
            normalized = 0;
        }
    }

    total[N] = total[N] - readings[N][readIndex[N]];
    readings[N][readIndex[N]] = normalized;
    total[N] = total[N] + readings[N][readIndex[N]];

    readIndex[N]++;

    if (readIndex[N] > (reads - 1))
    {
        readIndex[N] = 0;
    }

    average[N] = total[N] / reads;
    if (average[N] > 1000)
    {
        average[N] = 1000;
    }

    //----------------SET AXIS----------------
    Joystick.setThrottle(average[N]);
}

void axisX(int analogPin, int switchNumber, int startValue, int endValue)
{
    int inputPin = analogPin;
    int pinValue = analogRead(inputPin);
    int N = switchNumber - 1;
    float normalized = 0;

    if (endValue > startValue)
    {
        endValue = endValue - clutchTopDeadzone;
        startValue = startValue + clutchBottomDeadzone;
        float gap = endValue - startValue;
        float normFactor = 1000 / gap;
        normalized = normFactor * (pinValue - startValue);
        if (normalized < 0)
        {
            normalized = 0;
        }
    }
    else if (endValue < startValue)
    {
        endValue = endValue + clutchTopDeadzone;
        startValue = startValue - clutchBottomDeadzone;
        float gap = startValue - endValue;
        float normFactor = 1000 / gap;
        normalized = normFactor * (startValue - pinValue);
        if (normalized < 0)
        {
            normalized = 0;
        }
    }

    total[N] = total[N] - readings[N][readIndex[N]];
    readings[N][readIndex[N]] = normalized;
    total[N] = total[N] + readings[N][readIndex[N]];

    readIndex[N]++;

    if (readIndex[N] > (reads - 1))
    {
        readIndex[N] = 0;
    }

    average[N] = total[N] / reads;
    if (average[N] > 1000)
    {
        average[N] = 1000;
    }

    //----------------SET AXIS----------------
    Joystick.setXAxis(average[N]);
}


void bitePot(int analogPin, int switchNumber, int startValue, int endValue)
{
    Joystick.setRyAxisRange(0, 1000);

    int inputPin = analogPin;
    int pinValue = analogRead(inputPin);
    int N = switchNumber - 1;
    float normalized = 0;

    if (endValue > startValue)
    {
        endValue = endValue - clutchTopDeadzone;
        startValue = startValue + clutchBottomDeadzone;
        float gap = endValue - startValue;
        float normFactor = 1000 / gap;
        normalized = normFactor * (pinValue - startValue);
        if (normalized < 0)
        {
            normalized = 0;
        }
    }
    else if (endValue < startValue)
    {
        endValue = endValue + clutchTopDeadzone;
        startValue = startValue - clutchBottomDeadzone;
        float gap = startValue - endValue;
        float normFactor = 1000 / gap;
        normalized = normFactor * (startValue - pinValue);
        if (normalized < 0)
        {
            normalized = 0;
        }
    }

    total[N] = total[N] - readings[N][readIndex[N]];
    readings[N][readIndex[N]] = normalized;
    total[N] = total[N] + readings[N][readIndex[N]];

    readIndex[N]++;

    if (readIndex[N] > (reads - 1))
    {
        readIndex[N] = 0;
    }

    average[N] = total[N] / reads;
    if (average[N] > 1000)
    {
        average[N] = 1000;
    }

    //----------------SET AXIS----------------
    bitePoint = average[N];
    Joystick.setRyAxis(bitePoint);
}
