/*
Copyright (c) 2015-2016, Intel Corporation

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <climits>
#include <random>
#include <typeinfo>
#include <algorithm>

int rand_dev ();
extern std::mt19937_64 rand_gen;

class Type {
    public:
        explicit Type () {};
        static Type* init (unsigned int _type_id);
        unsigned int get_id ();
        std::string get_name ();
        bool get_is_fp ();
        bool get_is_signed ();
        void set_max_value (uint64_t _max_val);
        uint64_t get_max_value ();
        void set_min_value (uint64_t _min_val);
        uint64_t get_min_value ();
        uint64_t get_abs_max ();
        uint64_t get_abs_min ();
        void set_bound_value (std::vector<uint64_t> bval);
        std::vector<uint64_t> get_bound_value ();
        void add_bound_value (uint64_t bval);
        bool check_val_in_domains (uint64_t val);
        bool check_val_in_domains (std::string val);
        static Type* get_rand_obj ();
        virtual uint64_t get_rand_value () = 0;
        virtual std::string get_rand_value_str () = 0;
        void dbg_dump();

    public:
        // TODO: change initialization mechanism in ir.cpp for type_table
        // Synchronize with other places
        enum TypeID {
            UCHAR,
            USHRT,
            UINT,
            ULINT,
            ULLINT,
            MAX_TYPE_ID
        };

    protected:
        unsigned int id;
        std::string name;
        uint64_t max_val;
        uint64_t min_val;
        uint64_t abs_max;
        uint64_t abs_min;
        std::vector<uint64_t> bound_val;
        bool is_fp;
        bool is_signed;
};

class TypeUCHAR : public Type {
    public:
        TypeUCHAR ();
        uint64_t get_rand_value ();
        std::string get_rand_value_str ();
};

class TypeUSHRT : public Type {
    public:
        TypeUSHRT ();
        uint64_t get_rand_value ();
        std::string get_rand_value_str ();
};

class TypeUINT : public Type {
    public:
        TypeUINT ();
        uint64_t get_rand_value ();
        std::string get_rand_value_str ();
};

class TypeULINT : public Type {
    public:
        TypeULINT ();
        uint64_t get_rand_value ();
        std::string get_rand_value_str ();
};

class TypeULLINT : public Type {
    public:
        TypeULLINT ();
        uint64_t get_rand_value ();
        std::string get_rand_value_str ();
};
