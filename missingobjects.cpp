#include <QtCore/QCoreApplication>
#include <cstdio>
#include <cstdlib>
#include "missingobjects.h"

missingObjects::missingObjects(int argc, char *argv[])
{
    Open_Files(argc, argv);
    Read_Lines();
    Display_Objects();
    Close_Files();
}


void missingObjects::Open_Files(int argc, char *argv[])
{
    arma1file = fopen ("ArmA1_Objects.txt", "rt");
    if (!arma1file)
    {
        printf ("error in ArmA1_Objects.txt\n");
        exit (1);
    }

    printf("Opened ArmA1_Objects.txt\n");

    arma2file = fopen ("ArmA2_Objects.txt", "rt");
    if (!arma2file)
    {
        printf ("error in ArmA2_Objects.txt\n");
        exit (1);
    }

    printf("Opened ArmA2_Objects.txt\n");

    output = fopen ("Missing_Objects.txt", "wt");
    if (!output)
    {
        printf ("error in Missing_Objects.txt\n");
        exit (1);
    }

    printf("Created Missing_Objects.txt\n");
}


void missingObjects::Read_Lines()
{
    //first read all the ArmA2_objects.txt into our array.
    while (!feof(arma2file))
    {
        fgets (ArmA2_Objects[i], 256, arma2file);
        i++;
    }

    // read another ArmA1_Object.txt line
    fgets (pmc_line, 256, arma1file);

    while (!feof(arma1file))
    {
        // we don't have match at this point.
        Match_Found = 0;
        i = 0;

        // loop until the array is checked.
        while (strlen (ArmA2_Objects[i]) > 1)
        {
            // if match was found, set variable to true.
            if (strcmp (pmc_line, ArmA2_Objects[i]) == 0)
            {
                Match_Found = 1;
                printf ("We matched pmc_line: %s to ArmA2_Objects[%i]: %s\n", pmc_line, i, ArmA2_Objects[i]);
            }
            i++;
        }

        // we have done the checking and we DON'T have a match.
        if (Match_Found == 0)
        {
            // write the unmatched object into output
            fputs (pmc_line, output);
            printf ("Writing UNmatched object: %s\n", pmc_line);
        }

        // read another ArmA1_Object.txt line
        fgets (pmc_line, 256, arma1file);
    }
}


void missingObjects::Display_Objects()
{
    // print them on the screen.
    i = 0;
    printf("Displaying all ArmA2_Objects array contents:\n");
    while (strlen (ArmA2_Objects[i]) > 1)
    {
        printf ("%s", ArmA2_Objects[i]);
        i++;
    }

    printf("\nAll done. ArmA2_Objects array size: %i\n", i);
}


void missingObjects::Close_Files()
{
    fclose (arma1file);
    fclose (arma2file);
    fclose (output);
}
