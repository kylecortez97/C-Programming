#include <stdio.h>

#include "faculty.h"

struct professor faculty[NUM_FACULTY] = {
  [0]  = { "Shafae, Michael",          "CS-540", "(657) 278-3291", "mshafae@fullerton.edu"     },
  [1]  = { "Barua, Susamma",           "CS-502", "(657) 278-3362", "sbarua@fullerton.edu"      },
  [2]  = { "Bein, Doina",              "CS-542", "(657) 278-4822", "dbein@fullerton.edu"       },
  [3]  = { "Chen, Ning",               "CS-546", "(657) 278-3293", "nchen@fullerton.edu"       },
  [4]  = { "Choi, James S.",           "CS-544", "(657) 278-7257", "jchoi@fullerton.edu"       },
  [5]  = { "Cong, Bin",                "CS-417", "(657) 278-2031", "bcong@fullerton.edu"       },
  [6]  = { "Gofman, Mikhail",          "CS-538", "(657) 278-7304", "mgofman@fullerton.edu"     },
  [7]  = { "Han, Wenlin",              "CS-542", "(657) 278-7151", "whan@fullerton.edu"        },
  [8]  = { "Holliday, Floyd",          "CS-513", "(657) 278-7021", "holliday@fullerton.edu"    },
  [9]  = { "Inventado, Paul S.",       "CS-534", "(657) 278-3821", "pinventado@fullerton.edu"  },
  [10] = { "Jo, Chang-Hyun",           "CS-425", "(657) 278-7255", "cjo@fullerton.edu"         },
  [11] = { "Panangadan, Anand",        "CS-538", "(657) 278-3998", "apanangadan@fullerton.edu" },
  [12] = { "Ryu, Christopher T.",      "CS-421", "(657) 278-7231", "tryu@fullerton.edu"        },
  [13] = { "Tian, Yun",                "CS-538", "(657) 278-2041", "ytian@fullerton.edu"       },
  [14] = { "Wang, Shawn",              "CS-532", "(657) 278-7258", "xwang@fullerton.edu"       },
  [15] = { "Wortman, Kevin",           "CS-538", "(657) 278-2968", "kwortman@fullerton.edu"    }
};

void print_professor(struct professor *p) {
  printf("%s\n%s\n%s\n%s\n", p->name, p->office, p->phone, p->email);
}