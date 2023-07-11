#include <stdio.h>
#include <cpuid.h>

void cpuid(unsigned int* eax, unsigned int* ebx, unsigned int* ecx, unsigned int* edx);

int main()
{
    unsigned int eax, ebx, ecx, edx;
    unsigned int lsize, assoc, cache;

    __cpuid(0x80000006, eax, ebx, ecx, edx);
    
    lsize = ecx & 0xff;
    assoc = (ecx >> 12) & 0x15;
    cache = (ecx >> 16) & 0xffff;

    printf("Cache L2 Line size: %d B, Assoc. type: %d, Cache size: %d KB.\n", lsize, assoc, cache);

    __cpuid(0x80000008, eax, ebx, ecx, edx);
    
    lsize = eax & 0xff;
    assoc = (eax >> 8) & 0xff;
    unsigned int numberofcores;
    numberofcores=ecx&0xff;
        printf("%Physical memory size: %d GB , VirtualMemory: %d GB,NumberOfPhysicalCores  : %d\n", lsize, assoc,numberofcores+1);

    __cpuid(0x1, eax, ebx, ecx, edx);

    eax=1;
    cpuid(&eax, &ebx, &ecx, &edx);
        unsigned int familyId = (eax >> 8) & 0xF;

    int a;
__asm__("mov $0x2, %eax\n\t");
__asm__("cpuid\n\t");
__asm__("mov %%eax, %0\n\t":"=r" (a));
//__asm__("mov %%edx, %0\n\t":"=r" (a));
//__asm__("mov %%ecx, %0\n\t":"=r" (a));
//__asm__("mov %%eax, %0\n\t":"=r" (a));

printf ("%0x\n", a);
}



void printBinary(unsigned int value)
{
    for (int i = 31; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
    printf("\n");
}

void cpuid(unsigned int* eax, unsigned int* ebx, unsigned int* ecx, unsigned int* edx) {
    asm volatile("cpuid" : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx): "a" (*eax));
}










