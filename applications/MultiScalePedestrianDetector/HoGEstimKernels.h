#ifndef __HOGESTIMKERNEL_H__
#define __HOGESTIMKERNEL_H__

#include "AutoTilerLibTypes.h"
#include "HoGEstimKernelsInit.h"
#include "HoGBasicKernels.h"
#include "HoGEstimBasicKernels.h"
#include "ResizeBasicKernels.h"
#define _HOG_L1_Memory_SIZE 16616
#define _HOG_L2_Memory_SIZE 0
extern char *HOG_L1_Memory; /* Size given for generation: 17000 bytes, used: 16616 bytes */
extern char *HOG_L2_Memory; /* Size used for generation: 0 bytes */
extern void PrimeMyHOG(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void BodyMyHOG(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void PrimeMyWeakHOGEstim(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void BodyMyWeakHOGEstim(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyResize_N1(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker);
extern void PrimeMyHOG_N1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void BodyMyHOG_N1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void PrimeMyWeakHOGEstim_N1(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void BodyMyWeakHOGEstim_N1(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyResize_N2(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker);
extern void PrimeMyHOG_N2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void BodyMyHOG_N2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void PrimeMyWeakHOGEstim_N2(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void BodyMyWeakHOGEstim_N2(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyResize_N3(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker);
extern void PrimeMyHOG_N3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void BodyMyHOG_N3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void PrimeMyWeakHOGEstim_N3(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void BodyMyWeakHOGEstim_N3(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyResize_1(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker);
extern void PrimeMyHOG_1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void BodyMyHOG_1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void PrimeMyWeakHOGEstim_1(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void BodyMyWeakHOGEstim_1(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyResize_2(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker);
extern void PrimeMyHOG_2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void BodyMyHOG_2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void PrimeMyWeakHOGEstim_2(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void BodyMyWeakHOGEstim_2(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyResize_3(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker);
extern void PrimeMyHOG_3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void BodyMyHOG_3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker);
extern void PrimeMyWeakHOGEstim_3(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void BodyMyWeakHOGEstim_3(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyHOG(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker);
extern void MyWeakHOGEstim(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyHOG_N1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker);
extern void MyWeakHOGEstim_N1(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyHOG_N2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker);
extern void MyWeakHOGEstim_N2(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyHOG_N3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker);
extern void MyWeakHOGEstim_N3(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyHOG_1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker);
extern void MyWeakHOGEstim_1(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyHOG_2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker);
extern void MyWeakHOGEstim_2(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
extern void MyHOG_3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker);
extern void MyWeakHOGEstim_3(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker);
#endif
