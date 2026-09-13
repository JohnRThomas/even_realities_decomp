#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "jbd013_api.h"
#include "string.h"

// Send the JBD013 VGA panel's SPI commands to the panel.
void send_cmd(uint8_t cmd) {
    uint8_t pBuf[1];

    pBuf[0] = cmd;
    spi_tx_frame(pBuf);
}

// Read the panel ID and return the panel ID.
void read_id(void) {
    uint8_t pBuf[3];

    printf("Readout panel ID:\n");
    spi_rx_frame(SPI_RD_ID, pBuf, 3);
}

// Read the unique panel ID and store it in the memory space pointed to by `pBuf`,
// the buffer space corresponding to the pointer must be at least 15 bytes in size.
void read_uid(void) {
    uint8_t pBuf[15];

    printf("Read panel unique ID:\n");
    spi_rx_frame(SPI_RD_UID, pBuf, 15);
}

// Write to the status register: register address `regAddr`, data to be written `data`.
void wr_status_reg(uint8_t regAddr, uint8_t data) {
    uint8_t pBuf[2];

    pBuf[0] = regAddr;
    pBuf[1] = data;

    spi_tx_frame(pBuf);
}

// Read the status register at address `regAddr` and return the register data.
void rd_status_reg(uint8_t regAddr) {
    uint8_t pBuf[1];

    printf("Read Status Register: 0x%02X\n", regAddr);
    spi_rx_frame(regAddr, pBuf, 1);
}

// Write to the offset register: row offset address (0–31) and column offset address (0–31).
void wr_offset_reg(uint8_t row, uint8_t col) {
    uint8_t pBuf[3];

    pBuf[0] = 0xc0;
    pBuf[1] = row;
    pBuf[2] = col;

    spi_tx_frame(pBuf);
    send_cmd(SPI_SYNC); //Send command, synchronize data
    usleep(1 * 1000);   //1ms (8MHz) or 0.5ms (16MHz)
}

// Read the offset register and return the register data.
void rd_offset_reg(void) {
    uint8_t pBuf[2];

    printf("Read offset register: \n");
    spi_rx_frame(SPI_RD_OFFSET_REG, pBuf, 2);
}

// 写电流寄存器，要写入的数据（范围为0~63）param
void wr_cur_reg(uint8_t param) {
    uint8_t pBuf[2];

    pBuf[0] = 0x46;
    pBuf[1] = param;
    spi_tx_frame(pBuf);
}

// 读电流寄存器，返回寄存器数据
void rd_cur_reg(void) {
    uint8_t pBuf[1];

    printf("读电流寄存器: \n");
    spi_rx_frame(SPI_RD_CURRENT_REG, pBuf, 1);
}

// 写亮度寄存器
// [self refresh frequency，param],[25Hz,(0~21331)],[50Hz,(0~10664)],[75Hz,(0~7109)]
// [100Hz,(0~5331)],[125Hz,(0~4264)],[150Hz,(0~3366)],[175Hz,(0~2907)],[200Hz,(0~2558)]
void wr_lum_reg(uint16_t param) {
    uint8_t pBuf[3];

    pBuf[0] = 0x36;
    pBuf[1] = param >> 8;
    pBuf[2] = param;
    spi_tx_frame(pBuf);
}

// 读亮度寄存器,返回寄存器数据
void rd_lum_reg(void) {
    uint8_t pBuf[2];

    printf("读亮度寄存器: \n");
    spi_rx_frame(SPI_RD_LUM_REG, pBuf, 2);
}

// 设置镜像模式，[param = 0：正常显示], [param = 1：仅左右镜像]
// [param = 2：只镜像上下], [param = 3：同时镜像上、下、左、右]
void set_mirror_mode(uint8_t param) {
    send_cmd(SPI_DISPLAY_DEFAULT_MODE);
    if (param == 1 || param == 3) {
        send_cmd(SPI_DISPLAY_RL);
    }
    if (param == 2 || param == 3) {
        send_cmd(SPI_DISPLAY_UD);
    }
    send_cmd(SPI_SYNC);
    usleep(1 * 1000);
}

// 清空缓存
void clr_cache(void) {
    uint8_t pBuf[10];
    uint32_t pBufLen = sizeof(pBuf);
    uint8_t addrStep = pBufLen * 2;
    uint16_t rowCnt, colCnt;

    memset(pBuf, 0, pBufLen);
    spi_wr_buffer(0,0,pBuf,pBufLen);
     for (rowCnt = 0; rowCnt < 480; rowCnt++) {
         for (colCnt = 0; colCnt < 640; colCnt += addrStep) {
             spi_wr_buffer(colCnt, rowCnt, pBuf, pBufLen);
         }
        if (640 % addrStep != 0) {
             spi_wr_buffer((640 - 640 % addrStep), rowCnt, pBuf, 640 % addrStep);
         }
     }
}

// 显示图像，指向图像数据的指针pBuf，图片数据的长度len（0~153600）
void display_image(uint16_t row, uint16_t col, uint8_t *pBuf, uint32_t len) {
    spi_wr_buffer(col, row, pBuf, len);
    send_cmd(SPI_SYNC);            //同步缓存数据
    usleep(1 * 1000);              //1ms (8MHz) 或 0.5ms (16MHz)
}

/**
* @brief Display image data (optimized version)
* @param row Starting row
* @param col Starting column
* @param pBuf Image data buffer
* @param len Data length
* @param sync Whether to synchronize immediately
 */
void display_image_sync(uint16_t row, uint16_t col, uint8_t *pBuf, uint32_t len, uint8_t sync) {
    spi_wr_buffer(col, row, pBuf, len);
    if (sync) {
        send_cmd(SPI_SYNC);            // 同步缓存数据
        usleep(1 * 1000);             // 1ms (8MHz) 或 0.5ms (16MHz)
    }
}

// 复位面板
void panel_rst(void) {
    send_cmd(SPI_RST_EN);
    send_cmd(SPI_RST);
    usleep(50 * 1000);
}

// 初始化面板
void panel_init(void) {
    panel_rst();                                // Reset panel
    send_cmd(SPI_WR_ENABLE);                // Enable writing
    wr_cur_reg(30);                       // Set current register
    wr_status_reg(SPI_WR_STATUS_REG1, 0x10); // Write status register 1, disable demura
    wr_lum_reg(1000);                       // Write brightness register
    wr_status_reg(SPI_WR_STATUS_REG2, 0x05);// Write status register 2
    clr_cache();                            // Clear cache
    wr_offset_reg(0, 0);                    // Set top-left offset
    wr_offset_reg(0, 20);                   // Set top-right offset
    wr_offset_reg(24, 0);                   // Set bottom-left offset
    wr_offset_reg(24, 20);                  // Set bottom-right offset
    wr_offset_reg(12, 10);                  // Set actual offset to center the screen
    wr_lum_reg(1000);                       // Write brightness register
    wr_cur_reg(30);                          // Set current register
    set_mirror_mode(1);                     // Default mirror mode
    send_cmd(SPI_DISPLAY_ENABLE);           // Enable display
    send_cmd(SPI_SYNC);                     // Synchronize
    usleep(1 * 1000);
}