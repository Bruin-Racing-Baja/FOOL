#include "filter.h"
#include<fstream>
class filter;

int test(std::vector<double> output, double* input, int input_size, double* coeff, int coeff_size) {
    filter testFilter(coeff, coeff_size, input, input_size);

    std::vector<double> testOutput = testFilter.output();
    if (testOutput.size() == 0) {
        std::cout << "output is empty" << std::endl;
        return -1;
    }

    if (testOutput.size() != output.size()) {
        std::cout << "output size does not match expected output size" << std::endl;
        return -1;
    }

    for (int i = 0; i < testOutput.size(); i++) {
        if (abs(testOutput[i] - output[i]) > 0.00000001){
            std::cout << "Expected Value: " << output[i] << " Returned Value: " << testOutput[i] << std::endl;
        }
    }
    std::cout << "Done with Tests" << std::endl;
    return 0;
}

double* fileReader(std::string binaryFile) {
    std::streampos size;
    char * memblock;
    double * double_values = nullptr;

    int i=0;

    std::ifstream file (binaryFile, std::ios::in|std::ios::binary|std::ios::ate);
    if (file.is_open())
    {
        size = file.tellg();


        memblock = new char [size];
        file.seekg (0, std::ios::beg);
        file.read (memblock, size);
        file.close();

        double_values = (double*)memblock;
    };

    return double_values; 
}

int main() {
    std::vector<double> output = { 0.0407361843196589,0.073340997242127,0.0543718473420524,0.0621903912769214,0.043578756151976,-0.0546870970574098,-0.147699490168591,-0.187345246726102,-0.244527796109349,-0.28579989771556,-0.338971160552883,-0.358591463213447,-0.390134011640137,-0.463419565487123,-0.518751098169879,-0.563871039921535,-0.632700178930847,-0.673046620476635,-0.692713093774196,-0.716352775093661,-0.71872531494594,-0.76244502282335,-0.786446211702289,-0.796198209613737,-0.823179968974073,-0.827074374648946,-0.79671197669709,-0.820559828787565,-0.83147839301727,-0.849850780244967,-0.841460820581062,-0.862125705298965,-0.84912537350971,-0.857035290000962,-0.834483574544713,-0.798765191892562,-0.732294459112577,-0.693625713775084,-0.608571900211095,-0.568824011564908,-0.542319289664841,-0.509568361402811,-0.436253966068113,-0.390837380431242,-0.327988285649681,-0.268371822438822,-0.206497063500554,-0.152412227251629,-0.095529082345092,-0.00507993650817267,0.0469251956202442,0.121704334645528,0.185344142727996,0.221079803162969,0.251987451209669,0.325162841924368,0.400339804427974,0.444649215713401,0.524455388260031,0.586761562560938,0.6546344815061,0.672569732375195,0.731741828555436,0.785846713695452,0.864941674681297,0.91822506665912,0.972682368037976,0.990975658178648,0.996807466273831,0.994985511989995,1.01531126431394,1.02322000525039,1.07576855793032,1.09538020245809,1.13994263270311,1.12241099432778,1.12253385155005,1.09337106537167,1.10698840921707,1.07519529325689,1.06233518452722,1.07720555957912,1.07324369332503,1.04551041225745,1.03964039512506,1.00474909151826,0.966059614239583,0.936207994002777,0.886356541884393,0.824554336130025,0.766953970299928,0.682112470266309,0.618909073324245,0.584620111675335,0.546754667179302,0.491558697069932,0.4579132758322,0.394202438531577,0.294191473300786,0.201940382169573};
    double input[100] = {0.0407361843196589,0.073340997242127,0.0543718473420524,0.0621903912769214,0.043578756151976,-0.0546870970574098,-0.147699490168591,-0.187345246726102,-0.244527796109349,-0.28579989771556,-0.338971160552883,-0.358591463213447,-0.390134011640137,-0.463419565487123,-0.518751098169879,-0.563871039921535,-0.632700178930847,-0.673046620476635,-0.692713093774196,-0.716352775093661,-0.71872531494594,-0.76244502282335,-0.786446211702289,-0.796198209613737,-0.823179968974073,-0.827074374648946,-0.79671197669709,-0.820559828787565,-0.83147839301727,-0.849850780244967,-0.841460820581062,-0.862125705298965,-0.84912537350971,-0.857035290000962,-0.834483574544713,-0.798765191892562,-0.732294459112577,-0.693625713775084,-0.608571900211095,-0.568824011564908,-0.542319289664841,-0.509568361402811,-0.436253966068113,-0.390837380431242,-0.327988285649681,-0.268371822438822,-0.206497063500554,-0.152412227251629,-0.095529082345092,-0.00507993650817267,0.0469251956202442,0.121704334645528,0.185344142727996,0.221079803162969,0.251987451209669,0.325162841924368,0.400339804427974,0.444649215713401,0.524455388260031,0.586761562560938,0.6546344815061,0.672569732375195,0.731741828555436,0.785846713695452,0.864941674681297,0.91822506665912,0.972682368037976,0.990975658178648,0.996807466273831,0.994985511989995,1.01531126431394,1.02322000525039,1.07576855793032,1.09538020245809,1.13994263270311,1.12241099432778,1.12253385155005,1.09337106537167,1.10698840921707,1.07519529325689,1.06233518452722,1.07720555957912,1.07324369332503,1.04551041225745,1.03964039512506,1.00474909151826,0.966059614239583,0.936207994002777,0.886356541884393,0.824554336130025,0.766953970299928,0.682112470266309,0.618909073324245,0.584620111675335,0.546754667179302,0.491558697069932,0.4579132758322,0.394202438531577,0.294191473300786,0.201940382169573};
    double* coeff = fileReader("\\Users\\conwa\\Desktop\\FOOL\\coeff.bin");
    test(output, input, 100, coeff, 5);
    delete[] coeff;
    return 1;
}