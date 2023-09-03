#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Time step functions
#include <math.h> // Rand mathematical functions

#define NUM_COMPONENTS 8 // Adjusted for particle accelerator components
#define NUM_MAGNETS 16   // Number of magnetic elements

// Define accelerator components and variables
typedef struct {
    char name[50];
    double energy; // in GeV
    double beamIntensity; // in particles per second
    double beamSize; // in mm
    double vacuumPressure; // in Torr
    double magneticField; // in Tesla
    double radioFrequency; // in MHz
    double beamPower; // in kW
    double coolingSystem; // in liters per minute
} Component;

typedef struct {
    double particleEnergy; // in GeV
    char particleType[50];
    Component components[NUM_COMPONENTS];
} Accelerator;

// Initialize accelerator with default values
Accelerator initAccelerator() {
    Accelerator accelerator;
    accelerator.particleEnergy = 10.0; // Default particle energy in GeV
    strcpy(accelerator.particleType, "Sand"); // Default particle type is Sand

    // Initialize other components and properties
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        strcpy(accelerator.components[i].name, "Component");
        accelerator.components[i].energy = 0.0; // Initial energy in GeV
        accelerator.components[i].beamIntensity = 0.0; // Initial beam intensity
        accelerator.components[i].beamSize = 0.0; // Initial beam size in mm
        accelerator.components[i].vacuumPressure = 0.0; // Initial vacuum pressure in Torr
        accelerator.components[i].magneticField = 0.0; // Initial magnetic field in Tesla
        accelerator.components[i].radioFrequency = 0.0; // Initial RF frequency in MHz
        accelerator.components[i].beamPower = 0.0; // Initial beam power in kW
        accelerator.components[i].coolingSystem = 0.0; // Initial cooling system flow rate in liters per minute
    }

    return accelerator;
}

// Function to simulate time step for accelerator components
void simulateTimeStep(Accelerator *accelerator) {
    for (int i = 0; i < NUM_COMPONENTS; i++) {
        // Introduce small variations in component properties
        accelerator->components[i].energy += (rand() % 4 - 2) * 0.01; // Fluctuating energy by +/- 0.01 GeV
        accelerator->components[i].beamIntensity += (rand() % 10 - 5) * 0.01; // Fluctuating intensity by +/- 0.01
        accelerator->components[i].beamSize += (rand() % 4 - 2) * 0.01; // Fluctuating size by +/- 0.01 mm
        accelerator->components[i].vacuumPressure += (rand() % 10 - 5) * 0.01; // Fluctuating pressure by +/- 0.01 Torr
        accelerator->components[i].magneticField += (rand() % 10 - 5) * 0.01; // Fluctuating field by +/- 0.01 Tesla
        accelerator->components[i].radioFrequency += (rand() % 10 - 5) * 0.01; // Fluctuating frequency by +/- 0.01 MHz
        accelerator->components[i].beamPower += (rand() % 10 - 5) * 0.01; // Fluctuating power by +/- 0.01 kW
        accelerator->components[i].coolingSystem += (rand() % 10 - 5) * 0.01; // Fluctuating flow rate by +/- 0.01 liters per minute
    }
}

// Function to change accelerator's particle energy and type
void changeParticleEnergy(Accelerator *accelerator, double newParticleEnergy, const char *newParticleType) {
    accelerator->particleEnergy = newParticleEnergy;
    strcpy(accelerator->particleType, newParticleType);
    
    // Adjust accelerator components based on the new particle type
    // You can add specific adjustments for different particle types here
    if (strcmp(newParticleType, "Sand") == 0) {
        // Adjustments for sand particles (if needed)
    }
}

// Function to print an ASCII representation of the APPA
void printAPPA() {
    printf("\n");
    printf("     ___      ___       ___        \n");
    printf("    /   \\    /   \\     /   \\       \n");
    printf("   |     |  |     |   |     |      \n");
    printf("    \\___/    \\___/     \\___/       \n");
    printf("    ============================  \n");
    printf("    |           APPA           |  \n");
    printf("    ============================  \n");
    printf("\n");
}

void printCommonProperties(Accelerator *accelerator) {
    Component *commonComponent = &accelerator->components[0];
    printf("Common Component Properties:\n");
    printf(" - Energy: %.2f GeV\n", commonComponent->energy);
    printf(" - Beam Intensity: %.2f particles/s\n", commonComponent->beamIntensity);
    printf(" - Beam Size: %.2f mm\n", commonComponent->beamSize);
    printf(" - Vacuum Pressure: %.2f Torr\n", commonComponent->vacuumPressure);
    printf(" - Magnetic Field: %.2f Tesla\n", commonComponent->magneticField);
    printf(" - RF Frequency: %.2f MHz\n", commonComponent->radioFrequency);
    printf(" - Beam Power: %.2f kW\n", commonComponent->beamPower);
    printf(" - Cooling System Flow: %.2f liters/min\n", commonComponent->coolingSystem);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Accelerator accelerator = initAccelerator();

    printf("Air Pressurized Particle Accelerator Simulator (APPAs)\n");
    
    while (1) {
        char command[50];
        printf("Enter a command ('exit' to quit, 'help' for command list): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting simulator.\n");
            break;
        } else if (strcmp(command, "changeEnergy") == 0) {
            double newParticleEnergy;
            char newParticleType[50];
            printf("Enter new particle energy (GeV): ");
            scanf("%lf", &newParticleEnergy);
            printf("Enter new particle type: ");
            scanf("%s", newParticleType);
            changeParticleEnergy(&accelerator, newParticleEnergy, newParticleType);
            printf("Particle energy and type changed.\n");
        } else if (strcmp(command, "simulate") == 0) {
            simulateTimeStep(&accelerator);
            printf("Simulation complete.\n");
        } else if (strcmp(command, "status") == 0) {
            printf("Accelerator Status:\n");
            printf("Particle Energy: %.2f GeV\n", accelerator.particleEnergy);
            printf("Particle Type: %s\n", accelerator.particleType);
            printCommonProperties(&accelerator);
            printAPPA();
        } else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf(" - exit\n");
            printf(" - changeEnergy\n");
            printf(" - simulate\n");
            printf(" - status\n");
        } else {
            printf("Unknown command. Type 'help' for command list.\n");
        }
    }

    return 0;
}
