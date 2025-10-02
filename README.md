# Convert Encoding

[![GitHub Release](https://img.shields.io/github/v/release/exsycore/convert-encoding.svg)](https://github.com/exsycore/convert-encoding/releases/latest)
[![Download](https://img.shields.io/github/downloads/exsycore/convert-encoding/total?color=%233498db)](https://github.com/exsycore/convert-encoding/releases/latest)

ปลั๊กอิน Convert Encoding ช่วยแปลงให้ข้อความของคุณเป็น Encoding อื่นๆเช่น UTF-8 ได้หรือสามารถแปลงกลับไปเป็น TIS-620 ได้เลย

## การติดตั้ง (open.mp)
* นำไฟล์ [c2u.dll](c2u.dll) ใส่ในโฟลเดอร์ components ของคุณ (ไม่ต้องเพิ่มอะไร config.json สามารถใช้งานได้เลย)
```bash
│ GameMode/
├── components/
│   └── c2u.dll
```

* นำไฟล์ [ConvertEncoding.inc](https://github.com/exsycore/convert-encoding/blob/master/Source/ConvertEncoding.inc) ใส่ในโฟลเดอร์ Includes ของคุณ
```bash
│ qawno/
├── include/
│   └── ConvertEncoding.inc
```

* การติดตั้ง
```Pawn
#include <open.mp>
#include <ConvertEncoding>
```

## การบิ้ว

## Sources
```bash
git clone --recursive https://github.com/exsycore/convert-encoding.git
```

## Building on Windows
```bash
cmake -B build -A Win32 -T ClangCL
cmake --build build
```