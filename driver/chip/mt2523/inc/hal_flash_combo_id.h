/* Copyright Statement:
 *
 */

COMBO_MEM_TYPE_MODIFIER COMBO_MEM_TYPE_NAME COMBO_MEM_INST_NAME = {
    COMBO_MEM_STRUCT_HEAD
    {
        // MTKSIP_2523_SF_32_01
        CMEM_TYPE_SERIAL_NOR_FLASH,
        3,  // Valid ID length
        {0xC2, 0x28, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00}  // Flash ID
    },
    {
        // MTKSIP_2523_SF_32_01
        CMEM_TYPE_SERIAL_NOR_FLASH,
        3,  // Valid ID length
        {0xC2, 0x28, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00}  // Flash ID
    },
    {
        // MTKSIP_2523_SF_32_02
        CMEM_TYPE_SERIAL_NOR_FLASH,
        3,  // Valid ID length
        {0xEF, 0x70, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00}  // Flash ID
    },
    {
        // MTKSIP_2523_SF_32_03
        CMEM_TYPE_SERIAL_NOR_FLASH,
        3,  // Valid ID length
        {0xC2, 0x25, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00}  // Flash ID
    },
   
    {
        // MTKSIP_2523_SF_32_05
        CMEM_TYPE_SERIAL_NOR_FLASH,
        3,  // Valid ID length
        {0xEF, 0x40, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00}  // Flash ID
    }

    COMBO_MEM_STRUCT_FOOT
};
