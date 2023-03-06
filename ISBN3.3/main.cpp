#include "testSolution.h"

int main() {
    string test_path = "D:\\ISBN\\test2";

    string sample_path = "D:\\ISBN\\datasets";

    testSolution* test = new testSolution(sample_path);

    auto res = test->test(test_path);

    //cout << endl;
    //cout << res.first << " " << res.second << endl;
    cout << "正确率为：" << res.first * 100 << "%" << endl;
    cout << "准确率为：" << res.second * 100 << "%" << endl;

    return 0;
}