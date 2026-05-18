# Convert Encoding

[![GitHub Release](https://img.shields.io/github/v/release/exsycore/convert-encoding.svg)](https://github.com/exsycore/convert-encoding/releases/latest)
[![Download](https://img.shields.io/github/downloads/exsycore/convert-encoding/total?color=%233498db)](https://github.com/exsycore/convert-encoding/releases/latest)

ปลั๊กอิน Convert Encoding ช่วยแปลงให้ข้อความของคุณเป็น Encoding อื่นๆเช่น UTF-8 ได้หรือสามารถแปลงกลับไปเป็น TIS-620 ได้เลย

## การติดตั้ง (open.mp)
* นำไฟล์ [encore.dll](encore.dll) ใส่ในโฟลเดอร์ plugins ของคุณ (เพิ่มบรรทัด plugins ขึ้นมาแล้วพิมพ์ต่อว่า encore.dll)
```bash
│ GameMode/
├── plugins/
│   └── encore.dll
```

* นำไฟล์ [ConvertEncoding.inc](https://github.com/exsycore/convert-encoding/blob/samp/src/ConvertEncoding.inc) ใส่ในโฟลเดอร์ Includes ของคุณ
```bash
│ pawno/
├── include/
│   └── ConvertEncoding.inc
```

* การติดตั้ง
```Pawn
#include <a_samp>
#include <ConvertEncoding>
```

# วิธีการใช้งาน (นี่คือตัวอย่างเท่านั้น)
```Pawn
#include <a_samp>
#include <ConvertEncoding>

public OnPlayerConnect(playerid) {
    new string[100] = "สวัสดีนะจ๊ะจ๊ะจ๊ะ";
    new output[100], output2[100];

    ConvertEncoding(string, TIS620, UTF8, output);  // อันนี้ TIS-620 ไปเป็น UTF-8
    ConvertEncoding(output, UTF8, TIS620, output2); // อันนี้ UTF-8 ไปเป็น TIS-620

    SendClientMessage(playerid, COLOR_RED, output);
    SendClientMessage(playerid, COLOR_RED, output2);
    return 1;
}
```

## การบิ้ว

## Sources
```bash
git clone --recursive https://github.com/exsycore/convert-encoding.git
```

## Building on Windows
```bash
cmake -B build -A Win32
cmake --build build
```