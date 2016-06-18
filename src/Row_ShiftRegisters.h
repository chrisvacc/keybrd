#ifndef ROW_SHIFTREGISTERS_H
#define ROW_SHIFTREGISTERS_H

#include <RowBase.h>
#include <RowScanner_SPIShiftRegisters.h>
#include <Debouncer_4Samples.h>

/* Row_DH_IOE is a row connected to an Input/Output Expander.

Instantiation
-------------
Definition of DELAY_MICROSECONDS is explained in RowBase.cpp.
Example instantiation of a row:

    const unsigned int RowBase::DELAY_MICROSECONDS = 1000;

    todo

    Key* const ptrsKeys_0[] = { &k_00, &k_01, &k_02, &k_03, &k_04, &k_05 };
    Row_ShiftRegisters row_0(uint8_t BYTE_COUNT, ptrsKeys_0);

Number of pins in colPort0 should equal number of keys in ptrsKeys_0[] array.
    if a pin is missing, a key will be unresposive
    if a Key pointer is missing, the keyboard will fail in an unprdictable way
*/
class Row_ShiftRegisters : public RowBase
{
    private:
        RowScanner_SPIShiftRegisters scanner;
        Debouncer_4Samples debouncer;
    public:
        Row_ShiftRegisters(const uint8_t SS, uint8_t BYTE_COUNT, Key *const ptrsKeys[], uint16_t KEY_COUNT)
            : RowBase(ptrsKeys), scanner(SS, BYTE_COUNT, KEY_COUNT) { }
        void begin();
        uint8_t scan(uint16_t& rowEnd);
        uint8_t debounce(const uint8_t rowState, uint8_t& debounced);
};
#endif
