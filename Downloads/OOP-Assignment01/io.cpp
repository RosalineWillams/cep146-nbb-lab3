#include "io.h"
#include <iostream>
using namespace std;

namespace seneca {

    void read(char name[]) {
        cout << "name>\n ";
        cin >> name;
    }

    void print(long long phoneNum) {
        long long area = phoneNum / 10000000;
        long long mid = (phoneNum / 10000) % 1000;
        long long last = phoneNum % 10000;
        printf("(%03lld) %03lld-%04lld", area, mid, last);
    }

    void print(const PhoneRec& rec, size_t& row, const char* filter) {
        bool show = false;

        if (filter == nullptr) {
            show = true;
        } else {
            if (strstr(rec.m_name, filter) || strstr(rec.m_lastName, filter)) {
                show = true;
            }
        }

        if (show) {
            cout << row << ": " << rec.m_name << " " << rec.m_lastName << " ";
            print(rec.m_phoneNumber);
            cout << endl;
            row++;
        }
    }

    bool read(PhoneRec& rec, FILE* fptr) {
        return fscanf(fptr, "%s %s %lld",
            rec.m_name,
            rec.m_lastName,
            &rec.m_phoneNumber) == 3;
    }

    void print(PhoneRec* recArr[], size_t size, const char* filter) {
        size_t row = 1;  // ✅ 從 1 開始
        for (size_t i = 0; i < size; i++) {
            print(*recArr[i], row, filter);
        }
    }

    void setPointers(PhoneRec* ptrArr[], PhoneRec recArr[], size_t size) {
        for (size_t i = 0; i < size; i++) {
            ptrArr[i] = &recArr[i];
        }
    }

    void sort(PhoneRec* ptrArr[], size_t size, bool byLastName) {
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = i + 1; j < size; j++) {
                int cmp;

                if (byLastName) {
                    cmp = strcmp(ptrArr[i]->m_lastName, ptrArr[j]->m_lastName);
                } else {
                    cmp = strcmp(ptrArr[i]->m_name, ptrArr[j]->m_name);
                }

                if (cmp > 0) {
                    PhoneRec* temp = ptrArr[i];
                    ptrArr[i] = ptrArr[j];
                    ptrArr[j] = temp;
                }
            }
        }
    }
}