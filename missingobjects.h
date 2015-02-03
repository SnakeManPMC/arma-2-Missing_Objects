#ifndef MISSINGOBJECTS_H
#define MISSINGOBJECTS_H

class missingObjects
{
public:
    missingObjects(int argc, char *argv[]);
    void Open_Files(int argc, char *argv[]);
    void Read_Lines();
    void Display_Objects();
    void Close_Files();

private:
    FILE *arma1file;
    FILE *arma2file;
    FILE *output;

    char pmc_line[256];
    // line lenght 256 characters, array size 4096.
    char ArmA2_Objects[4096][256];
    int i, Match_Found;
};

#endif // MISSINGOBJECTS_H
