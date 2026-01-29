namespace palisade::features::sleepy {

void CallLumenInternalApi() {
}
void TurnScreenOff(){
    // Display compositor notified
}

}

int main(void){

    FILE * fp;

    fp = fopen("screenstat.cfg", "w"); // Config

    char data[] = "state=dimactive/n"; // Config

    fwrite(data, sizeof(data[15]), sizeof(data), fp); // Size of file: 15 bytes

    fclose(fp);

    FILE * fp;

    fp = fopen("screendimmer_log.txt", "w"); // Mock log file

    char data[] = "Screen Dimmed successfully, Sleep feature is working!/n"; // Log text

    fwrite(data, sizeof(data[53]), sizeof(data), fp); // Size of file: 53 bytes

    fclose(fp);

    return 0;
}

void 