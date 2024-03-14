#include <bits/stdc++.h>
using namespace std;

struct Blocks {
    int block_no=-1, block_size=0, file_no=-1, file_size=0, fragmentation=0;
    bool allocated = false;
};

int main() {
    freopen("PartitionData.txt", "r", stdin);
    int nb, nf;
    cin >> nb;
    struct Blocks blocks[nb];
    for(int i=0; i<nb; i++) {
        cin >> blocks[i].block_size;
        blocks[i].block_no = i+1;
    }
    cin >> nf;
    int files[nf];
    for(int i = 0; i<nf; i++) {
        cin >> files[i];
    }

    // FIRST FIT ALGORITHM
    for(int i=0; i<nf; i++) {
        int file_size = files[i];
        for(int j=0; j<nb; j++) {
            if((blocks[j].block_size >= file_size) && (blocks[j].allocated == false)) {
                blocks[j].file_no = i+1;
                blocks[j].file_size = file_size;
                blocks[j].fragmentation = blocks[j].block_size - file_size;
                blocks[j].allocated = true;
                break;
            }
        }
    }

    // PRINTING TABLE
    cout << "B.No\tB.Size\tFileNo\tFileSize\tFragmentation" << endl;
    for(int i=0; i<nb; i++) {
        cout << blocks[i].block_no << "\t" << blocks[i].block_size
            << "\t" << blocks[i].file_no << "\t" << blocks[i].file_size << "\t\t"
            << blocks[i].fragmentation << endl;
    }

    return 0;
}