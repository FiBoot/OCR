#include <QDir>
#include <QString>
#include "learningprocess.h"

LearningProcess::LearningProcess()
{
    num_input = 2500;
    num_output = 1;
    num_layer = 10;
    num_neurons_hidden = 1000;

    ann =   fann_create_standard(num_layer,num_input,num_neurons_hidden,num_output);
    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

    abcLearning[0][0] = 'A';
    abcLearning[1][0] = 'a';
    abcLearning[2][0] = 'B';
    abcLearning[3][0] = 'b';
    abcLearning[4][0] = 'C';
    abcLearning[5][0] = 'c';
    abcLearning[6][0] = 'D';
    abcLearning[7][0] = 'd';
    abcLearning[8][0] = 'E';
    abcLearning[9][0] = 'e';
    abcLearning[10][0] = 'F';
    abcLearning[11][0] = 'f';
    abcLearning[12][0] = 'G';
    abcLearning[13][0] = 'g';
    abcLearning[14][0] = 'H';
    abcLearning[15][0] = 'h';
    abcLearning[16][0] = 'I';
    abcLearning[17][0] = 'i';
    abcLearning[18][0] = 'J';
    abcLearning[19][0] = 'j';
    abcLearning[20][0] = 'K';
    abcLearning[21][0] = 'k';
    abcLearning[22][0] = 'L';
    abcLearning[23][0] = 'l';
    abcLearning[24][0] = 'M';
    abcLearning[25][0] = 'm';
    abcLearning[26][0] = 'N';
    abcLearning[27][0] = 'n';
    abcLearning[28][0] = 48;
    abcLearning[29][0] = 49;
    abcLearning[30][0] = 50;
    abcLearning[31][0] = 51;
    abcLearning[32][0] = 52;
    abcLearning[33][0] = 53;
    abcLearning[34][0] = 54;
    abcLearning[35][0] = 55;
    abcLearning[36][0] = 56;
    abcLearning[37][0] = 57;
    abcLearning[38][0] = 'O';
    abcLearning[39][0] = 'o';
    abcLearning[40][0] = 'P';
    abcLearning[41][0] = 'p';
    abcLearning[42][0] = 'Q';
    abcLearning[43][0] = 'q';
    abcLearning[44][0] = 'R';
    abcLearning[45][0] = 'r';
    abcLearning[46][0] = 'S';
    abcLearning[47][0] = 's';
    abcLearning[48][0] = 38;
    abcLearning[49][0] = 96;
    abcLearning[50][0] = 64;
    abcLearning[51][0] = 39;
    abcLearning[52][0] = 92;
    abcLearning[53][0] = 94;
    abcLearning[54][0] = 58;
    abcLearning[55][0] = 44;
    abcLearning[56][0] = 36;
    abcLearning[57][0] = 61;
    abcLearning[58][0] = 33;
    abcLearning[59][0] = 62;
    abcLearning[60][0] = 45;
    abcLearning[61][0] = 123;
    abcLearning[62][0] = 40;
    abcLearning[63][0] = 91;
    abcLearning[64][0] = 60;
    abcLearning[65][0] = 35;
    abcLearning[66][0] = 37;
    abcLearning[67][0] = 124;
    abcLearning[68][0] = 43;
    abcLearning[69][0] = 46;
    abcLearning[70][0] = 63;
    abcLearning[71][0] = 34;
    abcLearning[72][0] = 125;
    abcLearning[73][0] = 41;
    abcLearning[74][0] = 93;
    abcLearning[75][0] = 59;
    abcLearning[76][0] = 47;
    abcLearning[77][0] = 32;
    abcLearning[78][0] = 42;
    abcLearning[79][0] = 126;
    abcLearning[80][0] = 95;
    abcLearning[81][0] = 'T';
    abcLearning[82][0] = 't';
    abcLearning[83][0] = 'U';
    abcLearning[84][0] = 'u';
    abcLearning[85][0] = 'V';
    abcLearning[86][0] = 'v';
    abcLearning[87][0] = 'W';
    abcLearning[88][0] = 'w';
    abcLearning[89][0] = 'X';
    abcLearning[90][0] = 'x';
    abcLearning[91][0] = 'Y';
    abcLearning[92][0] = 'y';
    abcLearning[93][0] = 'Z';
    abcLearning[94][0] = 'z';
}


void                LearningProcess::StartLearningProcess()
{
    double inputTab[2500] = {0};
    int j = 0;
    int i = 0;
    QString cheminDuRepertoire = "C:/Users/ASUS/workspace/OCR/trunk/example_dataset/step1/";
    QDir repertoire(cheminDuRepertoire);
    repertoire.setFilter(QDir::NoDotAndDotDot | QDir::Files);
    repertoire.setNameFilters(QStringList() << "*.bmp");

    //Parcours ton répertoire
    foreach(QFileInfo fileInfo, repertoire.entryInfoList())
    {
       //Ton traitement par fichier, par exemple :
        Bitmap *bitmap  = new Bitmap(fileInfo.absoluteFilePath().toStdString().c_str());
        if (bitmap->isValid)
        {
            std::stack<bool> stack = bitmap->negative();
            while (j > 2500)
            {
                inputTab[i] = stack.top();
                stack.pop();
                ++i;
            }
            j = 0;
            fann_train(ann, inputTab, abcLearning[i]);
            ++i;
        }
    }
}
