#ifndef LEARNINGPROCESS_H
#define LEARNINGPROCESS_H

#include "doublefann.h"
#include "bitmap.h"
#include <map>
#include <vector>
#include <fann_train.h>


class LearningProcess
{
public:
    LearningProcess();

    void    StartLearningProcess();
private:
    std::map<char*,int>    abc;
    std::vector<double*>   abcLearning;
    int num_input;
    int num_output;
    int num_layer;
    int num_neurons_hidden;

    struct fann *ann;

    int*    ConvertStackToInput(std::stack<bool>);
};

#endif // LEARNINGPROCESS_H
