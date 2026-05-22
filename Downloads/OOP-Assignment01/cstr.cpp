#include "cstr.h"

namespace seneca {
    char* strcat(char* des, const char* src) {
        size_t len = strlen(des);
        size_t i = 0;
        while (des && src && src[i]) {
            des[i + len] = src[i];
            i++;
        }
        des[i + len] = '\0';
        return des;
    }

    char tolower(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            ch += 'a' - 'A';
        return ch;
    }

    char* tolower(char* des, const char* src) {
        size_t i = 0;
        for (; des && src && src[i]; i++)
            des[i] = tolower(src[i]);
        des[i] = '\0';
        return des;
    }

    char* tolower(char* str) {
        for (size_t i = 0; str && str[i]; i++)
            str[i] = tolower(str[i]);
        return str;
    }

    int strcmp(const char* s1, const char* s2) {
        size_t i = 0;
        while (s1[i] && s2[i] && s1[i] == s2[i])
            i++;
        return s1[i] - s2[i];
    }

    int strcmp(const char* s1, const char* s2, size_t len) {
        size_t i = 0;
        while (i < len && s1[i] && s2[i] && s1[i] == s2[i])
            i++;
        return s1[i] - s2[i];
    }

    char* strcpy(char* des, const char* src) {
        size_t i;
        for (i = 0; src[i]; i++)
            des[i] = src[i];
        des[i] = '\0';
        return des;
    }

    char* strcpy(char* des, const char* src, size_t len) {
        size_t i;
        for (i = 0; i < len && src[i]; i++)
            des[i] = src[i];
        des[i] = '\0';
        return des;
    }

    char* strncpy(char* des, const char* src, size_t len) {
        size_t i = 0;
        while (i < len - 1 && src[i]) {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
        return des;
    }

    size_t strlen(const char* str) {
        size_t len = 0;
        for (; str && str[len]; len++);
        return len;
    }

    const char* strstr(const char* str, const char* toFind) {
        if (!str || !toFind || !*toFind)
            return str;
        size_t fLen = strlen(toFind);
        size_t sLen = strlen(str);
        for (size_t i = 0; i <= sLen - fLen; ++i) {
            bool match = true;
            for (size_t j = 0; j < fLen; ++j) {
                if (tolower(str[i+j]) != tolower(toFind[j])) {
                    match = false;
                    break;
                }
            }
            if (match)
                return &str[i];
        }
        return nullptr;
    }

    bool isalpha(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    bool isspace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }
}