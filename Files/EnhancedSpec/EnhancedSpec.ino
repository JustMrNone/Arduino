void ENHANCED_SPECTRUM() {
    int redIntensity = 0;
    int greenIntensity = 0;
    int blueIntensity = 0;
    
    // Start with deep red (infrared transition)
    for (redIntensity = 0; redIntensity <= 255; redIntensity++) {
        analogWrite(redPin, redIntensity);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 0);
        delay(15);
    }

    // Red to Orange
    for (greenIntensity = 0; greenIntensity <= 165; greenIntensity++) {
        analogWrite(redPin, 255);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 0);
        delay(15);
    }

    // Orange to Yellow
    for (greenIntensity = 166; greenIntensity <= 255; greenIntensity++) {
        analogWrite(redPin, 255);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 0);
        delay(15);
    }

    // Yellow to Chartreuse
    for (redIntensity = 255; redIntensity >= 127; redIntensity--) {
        analogWrite(redPin, redIntensity);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0);
        delay(15);
    }

    // Chartreuse to Green
    for (redIntensity = 127; redIntensity >= 0; redIntensity--) {
        analogWrite(redPin, redIntensity);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, 0);
        delay(15);
    }

    // Green to Spring Green
    for (blueIntensity = 0; blueIntensity <= 127; blueIntensity++) {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, blueIntensity);
        delay(15);
    }

    // Spring Green to Cyan
    for (blueIntensity = 128; blueIntensity <= 255; blueIntensity++) {
        analogWrite(redPin, 0);
        analogWrite(greenPin, 255);
        analogWrite(bluePin, blueIntensity);
        delay(15);
    }

    // Cyan to Azure
    for (greenIntensity = 255; greenIntensity >= 127; greenIntensity--) {
        analogWrite(redPin, 0);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Azure to Blue
    for (greenIntensity = 127; greenIntensity >= 0; greenIntensity--) {
        analogWrite(redPin, 0);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Blue to Violet
    for (redIntensity = 0; redIntensity <= 127; redIntensity++) {
        analogWrite(redPin, redIntensity);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Violet to Purple
    for (redIntensity = 128; redIntensity <= 255; redIntensity++) {
        analogWrite(redPin, redIntensity);
        analogWrite(greenPin, 0);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Purple to Pink
    for (greenIntensity = 0; greenIntensity <= 192; greenIntensity++) {
        analogWrite(redPin, 255);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Pink to White
    for (greenIntensity = 193; greenIntensity <= 255; greenIntensity++) {
        analogWrite(redPin, 255);
        analogWrite(greenPin, greenIntensity);
        analogWrite(bluePin, 255);
        delay(15);
    }

    // Optional: Fade to Black (complete spectrum)
    for (int i = 255; i >= 0; i--) {
        analogWrite(redPin, i);
        analogWrite(greenPin, i);
        analogWrite(bluePin, i);
        delay(15);
    }

    // Optional: Rainbow Pulse Effect
    for (int i = 0; i < 2; i++) {
        // Quick pulse through primary and secondary colors
        int colors[][3] = {
            {255, 0, 0},    // Red
            {255, 127, 0},  // Orange
            {255, 255, 0},  // Yellow
            {0, 255, 0},    // Green
            {0, 255, 255},  // Cyan
            {0, 0, 255},    // Blue
            {127, 0, 255},  // Violet
            {255, 0, 255}   // Magenta
        };

        for (int j = 0; j < 8; j++) {
            // Fade in
            for (int k = 0; k <= 255; k++) {
                analogWrite(redPin, (colors[j][0] * k) / 255);
                analogWrite(greenPin, (colors[j][1] * k) / 255);
                analogWrite(bluePin, (colors[j][2] * k) / 255);
                delay(5);
            }
            // Fade out
            for (int k = 255; k >= 0; k--) {
                analogWrite(redPin, (colors[j][0] * k) / 255);
                analogWrite(greenPin, (colors[j][1] * k) / 255);
                analogWrite(bluePin, (colors[j][2] * k) / 255);
                delay(5);
            }
        }
    }

    LCD.clear();
}

