#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>
#include "gamepad_kondo.h"

// 定義 Step 結構
struct Step {
  const int act_number;  // 動作編號
  const int spend_time;  // 花費時間
};

// 定義 Action 結構
struct Action {
  const char* key;                        // 動作的名稱
  const std::vector<Step> readyAction;    // 準備動作的步驟集合
  const std::vector<Step> doAction;       // 動作的步驟集合
  const std::vector<Step> endAction;      // 動作結束的步驟集合
};

// 初始化全局常量 forward : 向前
inline const std::vector<Action> forward = {

  // 移動
  // ==================================
  {
    KONDO_BUTTON_UP, 
    {},
    {{3, 35}, {4, 75}, {5, 35}, {6, 75}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_DOWN, 
    {},
    {{7, 35}, {8, 95}, {9, 35}, {10, 95}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_LEFT, 
    {},
    {{13, 70}, {12, 95}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_RIGHT, 
    {},
    {{14, 70}, {12, 95}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_L2, 
    {},
    {{16, 90}, {11, 90}}, 
    {{25, 100}, {1, 50}}
  },
  {
    KONDO_BUTTON_R2, 
    {},
    {{15, 90}, {17, 90}}, 
    {{25, 100}, {1, 50}}
  },

  // 圓 + R : 右攻擊
  // ==================================
  {
    KONDO_BUTTON_CIRCLE + KONDO_BUTTON_R1, 
    {{73, 150}},
    {{74, 50}}, 
    {{25, 50}}
  },
  {
    KONDO_BUTTON_CIRCLE + KONDO_BUTTON_R2, 
    {{63, 150}},
    {{64, 50}}, 
    {{25, 50}}
  },

  // 方 + L : 左攻擊
  // ==================================
  {
    KONDO_BUTTON_SQUARE + KONDO_BUTTON_L1, 
    {{71, 150}},
    {{72, 50}}, 
    {{25, 50}}
  },
  {
    KONDO_BUTTON_SQUARE + KONDO_BUTTON_L2, 
    {{75, 150}},
    {{76, 50}}, 
    {{25, 50}}
  },

  // L/R 1 : 敲背高
  // ==================================
  {
    KONDO_BUTTON_L1, 
    {{61, 50}},
    {{62, 50}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_R1, 
    {{65, 50}},
    {{66, 50}}, 
    {{25, 50}, {1, 50}}
  },

  // 方/圓 + 三角 : 敲背低
  // ==================================
  {
    KONDO_BUTTON_SQUARE + KONDO_BUTTON_TRIANGLE, // 左
    {{67, 50}},
    {{68, 50}}, 
    {{25, 100}, {1, 50}}
  },
  {
    KONDO_BUTTON_CIRCLE + KONDO_BUTTON_TRIANGLE, // 右
    {{69, 50}},
    {{70, 50}}, 
    {{25, 100}, {1, 50}}
  },

  // 左/右 + 上 : 八
  // ==================================
  {
    KONDO_BUTTON_LEFT + KONDO_BUTTON_UP, // 左
    {{43, 90}},
    {{44, 80}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_RIGHT + KONDO_BUTTON_UP, // 右
    {{45, 90}},
    {{46, 80}}, 
    {{25, 50}, {1, 50}}
  }
};

// 初始化全局常量 back : 向後
inline const std::vector<Action> back = {
    
  // 移動
  // ==================================
  {
    KONDO_BUTTON_UP, 
    {},
    {{7, 35}, {8, 95}, {9, 35}, {10, 95}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_DOWN, 
    {},
    {{3, 35}, {4, 75}, {5, 35}, {6, 75}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_LEFT, 
    {},
    {{13, 70}, {12, 95}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_RIGHT, 
    {},
    {{14, 70}, {12, 95}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_L2, 
    {},
    {{15, 90}, {17, 90}}, 
    {{25, 100}, {1, 50}}
  },
  {
    KONDO_BUTTON_R2, 
    {},
    {{16, 90}, {11, 90}}, 
    {{25, 100}, {1, 50}}
  },

  // 圓 + R : 右攻擊
  // ==================================
  {
    KONDO_BUTTON_CIRCLE + KONDO_BUTTON_R1, 
    {{57, 150}},
    {{58, 50}}, 
    {{25, 50}}
  },
  {
    KONDO_BUTTON_CIRCLE + KONDO_BUTTON_R2, 
    {{34, 150}},
    {{35, 50}}, 
    {{25, 50}}
  },

  // 方 + L : 左攻擊
  // ==================================
  {
    KONDO_BUTTON_SQUARE + KONDO_BUTTON_L1, 
    {{53, 150}},
    {{54, 50}}, 
    {{25, 50}}
  },
  {
    KONDO_BUTTON_SQUARE + KONDO_BUTTON_L2, 
    {{30, 150}},
    {{31, 50}}, 
    {{25, 50}}
  },

  // L/R 1 : 敲背高
  // ==================================
  {
    KONDO_BUTTON_L1, 
    {{36, 50}},
    {{37, 50}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_R1, 
    {{32, 50}},
    {{33, 50}}, 
    {{25, 50}, {1, 50}}
  },

  // 方/圓 + 三角 : 敲背低
  // ==================================
  {
    KONDO_BUTTON_SQUARE + KONDO_BUTTON_TRIANGLE, // 左
    {{39, 50}},
    {{40, 50}}, 
    {{25, 100}, {1, 50}}
  },
  {
    KONDO_BUTTON_CIRCLE + KONDO_BUTTON_TRIANGLE, // 右
    {{41, 50}},
    {{42, 50}}, 
    {{25, 100}, {1, 50}}
  },

  // 左/右 + 上 : 八
  // ==================================
  {
    KONDO_BUTTON_LEFT + KONDO_BUTTON_UP, // 左
    {{47, 90}},
    {{48, 80}}, 
    {{25, 50}, {1, 50}}
  },
  {
    KONDO_BUTTON_RIGHT + KONDO_BUTTON_UP, // 右
    {{49, 90}},
    {{50, 80}}, 
    {{25, 50}, {1, 50}}
  }
};

// 初始化全局常量 squat : 蹲下
inline const std::vector<Action> squat = {
    
  // 移動
  // ==================================
  {
    KONDO_BUTTON_LEFT, 
    {},
    {{13, 40}, {38, 90}}, 
    {{38, 10}}
  },
  {
    KONDO_BUTTON_RIGHT, 
    {},
    {{14, 40}, {38, 90}}, 
    {{38, 10}}
  },
  {
    KONDO_BUTTON_L2, 
    {},
    {{29, 80}, {38, 100}}, 
    {{38, 10}}
  },
  {
    KONDO_BUTTON_R2, 
    {},
    {{28, 80}, {38, 100}}, 
    {{38, 10}}
  }
};

// 初始化全局常量 common : 共同動作 -> 三個都有
inline const std::vector<Action> common = {

  // 三角 : 必殺技
  // ==================================
  {
    KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_UP, 
    {{77, 400}, {78, 320}},
    {{79, 50}}, 
    {}
  },
  {
    KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_DOWN, 
    {{38, 400}, {84, 150}},
    {{85, 50}}, 
    {}
  },
  {
    KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_LEFT, 
    {{80, 250}},
    {{81, 50}}, 
    {}
  },
  {
    KONDO_BUTTON_TRIANGLE + KONDO_BUTTON_RIGHT, 
    {{77, 400}, {78, 320}, {82, 500}},
    {{83, 50}}, 
    {}
  },

  // 其他 : 跌爬
  // ==================================
  {
    KONDO_BUTTON_LEFT + KONDO_BUTTON_DOWN, // 左跌爬
    {{20, 250}, {26, 400}},
    {{27, 50}}, 
    {{23, 350}, {61, 100}, {1, 50}}
  },
  {
    KONDO_BUTTON_CIRCLE + KONDO_BUTTON_CROSS, // 右跌爬
    {{20, 250}, {21, 250}},
    {{22, 50}}, 
    {{23, 350}, {61, 100}, {1, 50}}
  }
}

#endif // STATE_H