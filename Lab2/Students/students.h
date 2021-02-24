#pragma once
class students
{
    const char* name;
    float gr_math;
    float gr_eng;
    float gr_hist;
    float gr_average;
public:
    void set_name(const char *n); // name
    void set_gr_math(float grade); // grade for Mathematics
    void set_gr_eng(float grade); // grade for English
    void set_gr_hist(float grade); // grade for History
    const char* get_name();
    float get_gr_math();
    float get_gr_eng();
    float get_gr_hist();
    float get_gr_average();
    static int cmp_name(students a, students b);
    static int cmp_gr_math(students a, students b);
    static int cmp_gr_eng(students a, students b);
    static int cmp_gr_hist(students a, students b);
    static int cmp_gr_average(students a, students b);
};

