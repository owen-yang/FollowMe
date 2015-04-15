#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include <inttypes.h>

int rssiMint;
float distMint;

#define RSSI_MINT_ARR_SIZE 20
//int rssiMintArr[RSSI_MINT_ARR_SIZE];
float lpfRssiMintArr[RSSI_MINT_ARR_SIZE];

#define DIST_MINT_ARR_SIZE 20
float distMintArr[DIST_MINT_ARR_SIZE];

void initBluetooth();
void enableScan();
void enableAdv();
void connectToAddress(const char* address);

#endif /* BLUETOOTH_H_ */
