#include <Bela.h>
extern "C" {
int oled_main(void);  // declare the oled_main() function from Main.c
}
AuxiliaryTask oledTask;
void oledTaskFunction(void*)
{
    while(!gShouldStop){ // run the content of the loop until the program stops
        oled_main();
        usleep(50000); // always sleep in a busy loop to avoid hogging all the CPU
   }
}
bool setup(BelaContext* context, void* userData)
{
    oledTask = Bela_createAuxiliaryTask(oledTaskFunction, 1, "oledTask", NULL);
    Bela_scheduleAuxiliaryTask(oledTask);
    return true;
}
// optional: add some sound generator into render()

void render(BelaContext *context, void *userData)
{
}

void cleanup(BelaContext *context, void *userData)
{
}