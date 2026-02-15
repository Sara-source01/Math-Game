// Math Game.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };

enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };


string GetOpTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mult:
        return "x";
    case enOperationType::Div:
        return "/";
    default:
        return "Mix";
    }
}


string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
{
    string arrQuestionLevelText[4] = { "Easy","Medium","Hard","Mixed" };
    return arrQuestionLevelText[QuestionLevel - 1];
}


int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}


void SetScreenColor(bool Right)
{
    if (Right)
        system("color 2F"); // Green for correct answers.
    else
    {
        system("color 4F"); // Red for incorrect answers.
        cout << "\a"; // Plays an alert sound.
    }
}

short ReadHowManyQuestions()
{
    short NumberOfQuestions;

    do
    {
        cout << "How many questions do yoy want to answer? ";
        cin >> NumberOfQuestions;
    } while (NumberOfQuestions < 1 || NumberOfQuestions > 10);

    return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
    short QuestionLevel = 0;

    do
    {
        cout << "Enter questions level [1] Easy, [2] Med, [3] Hard, [4] Mix? ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 4);

    return (enQuestionsLevel) QuestionLevel;
}

enOperationType ReadOpType()
{
    short OpType;

    do
    {
        cout << "Enter operation level [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? ";
        cin >> OpType;
    } while (OpType < 1 || OpType > 5);

    return (enOperationType) OpType;
}

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType;
    enQuestionsLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};


struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionsLevel QuestionsLevel;
    enOperationType OpType;
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
    bool isPass = false;
};


int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mult:
        return Number1 * Number2;
    case enOperationType::Div:
        return (Number1 / Number2); 
    default:
        return Number1 + Number2;
    }
}

enOperationType GetRandomOperationType()
{
    int Op = RandomNumber(1, 4);
    return (enOperationType)Op;
}


int main()
{
    srand((unsigned)time(NULL));

    return 0;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
