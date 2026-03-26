#include "Vector.h"

using namespace std;
using json = nlohmann::json;

int main() {

    int size;
    cout << "Enter vector size: ";
    cin >> size;

    vector<double> v1 = generateVector(size);

    ofstream a("a.txt");
    for (double x : v1) a << x << " ";
    a.close();

    int n;
    cout << "Enter group size n: ";
    cin >> n;

    vector<double> sums = groupSums(v1, n);
    ofstream b("b.txt");
    for (double s : sums) b << s << endl;
    b.close();

    double S2 = sumVector(sums);

    vector<double> asc = v1;
    sortASC(asc);
    double w1 = sumVector(asc);

    vector<double> desc = v1;
    sortDESC(desc);
    double w2 = sumVector(desc);

    int repeats = 0;
    vector<double> unique = removeDuplicates(v1, repeats);
    double S3 = sumVector(unique);

    vector<double> best = maxGroup(v1, n);

    json result;
    result["S2"] = S2;
    result["S3"] = S3;
    result["S3_minus_S2"] = S3 - S2;
    result["w1"] = w1;
    result["w2"] = w2;
    result["w1_minus_w2"] = w1 - w2;

    result["repeated_elements"] = repeats;
    result["count_a_txt"] = v1.size();
    result["count_b_txt"] = sums.size();
    result["max_group"] = best;

    ofstream j("result.json");
    j << result.dump(4);
    j.close();

    cout << "Files created: a.txt, b.txt, result.json" << endl;
    return 0;
}