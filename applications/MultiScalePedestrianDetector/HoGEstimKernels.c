#include "HoGEstimKernelsInit.h"
#include "HoGEstimKernels.h"
void PrimeMyHOG(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 9248 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (322);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (322);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 3220, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<2; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 2); NextLast = ((Iter+2) == 2); NextNextLast = ((Iter+3) == 2);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*2576),
					(rt_pointerT) (HOG_L1_Memory + 0) + (3220*((N_Ti+1) % 2)), 3220, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 3220*((N_Ti) % 2));
		KerArg0->CellLineIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=2;
	/* Call Kernel LOC_INNER_LOOP_EPILOG */
	KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 6440) + 0);
	rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
	/* =======================Write Last Tile=========================================== */
	rt_dma_memcpy((rt_pointerT) HOGFeatures + 0,
		(rt_pointerT) (HOG_L1_Memory + 6440) + 0, 2808, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void BodyMyHOG(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 12056 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (322);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineIndex = (uint32_t) (2);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (322);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 3220, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<28; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 28); NextLast = ((Iter+2) == 28); NextNextLast = ((Iter+3) == 28);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*2576),
					(rt_pointerT) (HOG_L1_Memory + 0) + (3220*((N_Ti+1) % 2)), 3220, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 3220*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 6440) + 2808*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) HOGFeatures + ((Iter)*2808),
			(rt_pointerT) (HOG_L1_Memory + 6440) + (2808*(N_Ti % 2)), 2808, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=28;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyWeakHOGEstim(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 4176 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (29);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->ColumnIndexM1 = (uint32_t) (-1);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2088, 
		2808, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<7; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 7); NextLast = ((Iter+2) == 7); NextNextLast = ((Iter+3) == 7);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2088*((N_Ti+1) % 2)), 2088, 
					2808, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2088*((N_Ti) % 2));
		KerArg0->HoGFeatColIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=7;
	/* Call Kernel LOC_EPILOG */
	rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
}

void BodyMyWeakHOGEstim(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 4176 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (29);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg0->HoGFeatColIndex = (uint32_t) (7);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2088, 
		2808, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<32; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 32); NextLast = ((Iter+2) == 32); NextNextLast = ((Iter+3) == 32);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2088*((N_Ti+1) % 2)), 2088, 
					2808, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2088*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		KerArg1->ColumnIndexM1 = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=32;
}

void MyResize_N1(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 11600 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerResizeBilinear_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->Win = (unsigned int) (322);
	KerArg0->Hin = (unsigned int) (242);
	KerArg0->Wout = (unsigned int) (282);
	KerArg0->Hout = (unsigned int) (212);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) In+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 3542, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<27; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 27); NextLast = ((Iter+2) == 27); NextNextLast = ((Iter+3) == 27);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) In + (((74500*(Iter+1)*8)>>16)*322),
					(rt_pointerT) (HOG_L1_Memory + 0) + (3544*((N_Ti+1) % 2)), NextLast?1932:3542, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 3544*((N_Ti) % 2));
		KerArg0->Out = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 7088) + 2256*((N_Ti) % 2));
		KerArg0->HTileOut = (unsigned int) (Last?4:8);
		KerArg0->FirstLineIndex = (unsigned int) ((74500*Iter*8)>>16);
		rt_team_fork(gap8_ncore(), (void *) KerResizeBilinear, (void *) KerArg0);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) Out + ((Iter)*2256),
			(rt_pointerT) (HOG_L1_Memory + 7088) + (2256*(N_Ti % 2)), Last?1128:2256, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=27;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyHOG_N1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 8088 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (282);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (282);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2820, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<2; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 2); NextLast = ((Iter+2) == 2); NextNextLast = ((Iter+3) == 2);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*2256),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2820*((N_Ti+1) % 2)), 2820, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2820*((N_Ti) % 2));
		KerArg0->CellLineIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=2;
	/* Call Kernel LOC_INNER_LOOP_EPILOG */
	KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 5640) + 0);
	rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
	/* =======================Write Last Tile=========================================== */
	rt_dma_memcpy((rt_pointerT) HOGFeatures + 0,
		(rt_pointerT) (HOG_L1_Memory + 5640) + 0, 2448, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void BodyMyHOG_N1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 10536 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (282);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineIndex = (uint32_t) (2);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (282);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2820, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<24; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 24); NextLast = ((Iter+2) == 24); NextNextLast = ((Iter+3) == 24);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*2256),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2820*((N_Ti+1) % 2)), 2820, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2820*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 5640) + 2448*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) HOGFeatures + ((Iter)*2448),
			(rt_pointerT) (HOG_L1_Memory + 5640) + (2448*(N_Ti % 2)), 2448, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=24;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyWeakHOGEstim_N1(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 3600 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (25);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->ColumnIndexM1 = (uint32_t) (-1);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 1800, 
		2448, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<7; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 7); NextLast = ((Iter+2) == 7); NextNextLast = ((Iter+3) == 7);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (1800*((N_Ti+1) % 2)), 1800, 
					2448, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 1800*((N_Ti) % 2));
		KerArg0->HoGFeatColIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=7;
	/* Call Kernel LOC_EPILOG */
	rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
}

void BodyMyWeakHOGEstim_N1(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 3600 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (25);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg0->HoGFeatColIndex = (uint32_t) (7);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 1800, 
		2448, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<27; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 27); NextLast = ((Iter+2) == 27); NextNextLast = ((Iter+3) == 27);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (1800*((N_Ti+1) % 2)), 1800, 
					2448, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 1800*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		KerArg1->ColumnIndexM1 = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=27;
}

void MyResize_N2(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 12736 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerResizeBilinear_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->Win = (unsigned int) (322);
	KerArg0->Hin = (unsigned int) (242);
	KerArg0->Wout = (unsigned int) (242);
	KerArg0->Hout = (unsigned int) (182);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) In+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 4186, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<21; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 21); NextLast = ((Iter+2) == 21); NextNextLast = ((Iter+3) == 21);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) In + (((86781*(Iter+1)*9)>>16)*322),
					(rt_pointerT) (HOG_L1_Memory + 0) + (4188*((N_Ti+1) % 2)), NextLast?1288:4186, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 4188*((N_Ti) % 2));
		KerArg0->Out = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 8376) + 2180*((N_Ti) % 2));
		KerArg0->HTileOut = (unsigned int) (Last?2:9);
		KerArg0->FirstLineIndex = (unsigned int) ((86781*Iter*9)>>16);
		rt_team_fork(gap8_ncore(), (void *) KerResizeBilinear, (void *) KerArg0);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) Out + ((Iter)*2178),
			(rt_pointerT) (HOG_L1_Memory + 8376) + (2180*(N_Ti % 2)), Last?484:2178, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=21;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyHOG_N2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 6928 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (242);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (242);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2420, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<2; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 2); NextLast = ((Iter+2) == 2); NextNextLast = ((Iter+3) == 2);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*1936),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2420*((N_Ti+1) % 2)), 2420, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2420*((N_Ti) % 2));
		KerArg0->CellLineIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=2;
	/* Call Kernel LOC_INNER_LOOP_EPILOG */
	KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 4840) + 0);
	rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
	/* =======================Write Last Tile=========================================== */
	rt_dma_memcpy((rt_pointerT) HOGFeatures + 0,
		(rt_pointerT) (HOG_L1_Memory + 4840) + 0, 2088, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void BodyMyHOG_N2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 9016 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (242);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineIndex = (uint32_t) (2);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (242);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2420, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<20; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 20); NextLast = ((Iter+2) == 20); NextNextLast = ((Iter+3) == 20);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*1936),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2420*((N_Ti+1) % 2)), 2420, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2420*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 4840) + 2088*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) HOGFeatures + ((Iter)*2088),
			(rt_pointerT) (HOG_L1_Memory + 4840) + (2088*(N_Ti % 2)), 2088, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=20;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyWeakHOGEstim_N2(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 3024 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (21);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->ColumnIndexM1 = (uint32_t) (-1);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 1512, 
		2088, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<7; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 7); NextLast = ((Iter+2) == 7); NextNextLast = ((Iter+3) == 7);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (1512*((N_Ti+1) % 2)), 1512, 
					2088, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 1512*((N_Ti) % 2));
		KerArg0->HoGFeatColIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=7;
	/* Call Kernel LOC_EPILOG */
	rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
}

void BodyMyWeakHOGEstim_N2(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 3024 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (21);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg0->HoGFeatColIndex = (uint32_t) (7);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 1512, 
		2088, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<22; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 22); NextLast = ((Iter+2) == 22); NextNextLast = ((Iter+3) == 22);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (1512*((N_Ti+1) % 2)), 1512, 
					2088, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 1512*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		KerArg1->ColumnIndexM1 = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=22;
}

void MyResize_N3(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 13944 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerResizeBilinear_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->Win = (unsigned int) (322);
	KerArg0->Hin = (unsigned int) (242);
	KerArg0->Wout = (unsigned int) (202);
	KerArg0->Hout = (unsigned int) (152);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) In+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 5152, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<17; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 17); NextLast = ((Iter+2) == 17); NextNextLast = ((Iter+3) == 17);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) In + (((103909*(Iter+1)*9)>>16)*322),
					(rt_pointerT) (HOG_L1_Memory + 0) + (5152*((N_Ti+1) % 2)), NextLast?4508:5152, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 5152*((N_Ti) % 2));
		KerArg0->Out = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 10304) + 1820*((N_Ti) % 2));
		KerArg0->HTileOut = (unsigned int) (Last?8:9);
		KerArg0->FirstLineIndex = (unsigned int) ((103909*Iter*9)>>16);
		rt_team_fork(gap8_ncore(), (void *) KerResizeBilinear, (void *) KerArg0);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) Out + ((Iter)*1818),
			(rt_pointerT) (HOG_L1_Memory + 10304) + (1820*(N_Ti % 2)), Last?1616:1818, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=17;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyHOG_N3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 5768 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (202);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (202);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2020, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<2; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 2); NextLast = ((Iter+2) == 2); NextNextLast = ((Iter+3) == 2);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*1616),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2020*((N_Ti+1) % 2)), 2020, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2020*((N_Ti) % 2));
		KerArg0->CellLineIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=2;
	/* Call Kernel LOC_INNER_LOOP_EPILOG */
	KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 4040) + 0);
	rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
	/* =======================Write Last Tile=========================================== */
	rt_dma_memcpy((rt_pointerT) HOGFeatures + 0,
		(rt_pointerT) (HOG_L1_Memory + 4040) + 0, 1728, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void BodyMyHOG_N3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 7496 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (202);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineIndex = (uint32_t) (2);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (202);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2020, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<16; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 16); NextLast = ((Iter+2) == 16); NextNextLast = ((Iter+3) == 16);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*1616),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2020*((N_Ti+1) % 2)), 2020, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2020*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 4040) + 1728*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) HOGFeatures + ((Iter)*1728),
			(rt_pointerT) (HOG_L1_Memory + 4040) + (1728*(N_Ti % 2)), 1728, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=16;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyWeakHOGEstim_N3(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 2448 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (17);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->ColumnIndexM1 = (uint32_t) (-1);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 1224, 
		1728, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<7; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 7); NextLast = ((Iter+2) == 7); NextNextLast = ((Iter+3) == 7);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (1224*((N_Ti+1) % 2)), 1224, 
					1728, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 1224*((N_Ti) % 2));
		KerArg0->HoGFeatColIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=7;
	/* Call Kernel LOC_EPILOG */
	rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
}

void BodyMyWeakHOGEstim_N3(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 2448 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (17);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg0->HoGFeatColIndex = (uint32_t) (7);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 1224, 
		1728, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<17; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 17); NextLast = ((Iter+2) == 17); NextNextLast = ((Iter+3) == 17);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (1224*((N_Ti+1) % 2)), 1224, 
					1728, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 1224*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		KerArg1->ColumnIndexM1 = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=17;
}

void MyResize_1(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 15056 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerResizeBilinear_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->Win = (unsigned int) (322);
	KerArg0->Hin = (unsigned int) (242);
	KerArg0->Wout = (unsigned int) (362);
	KerArg0->Hout = (unsigned int) (272);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) In+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 3542, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<25; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 25); NextLast = ((Iter+2) == 25); NextNextLast = ((Iter+3) == 25);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) In + (((58066*(Iter+1)*11)>>16)*322),
					(rt_pointerT) (HOG_L1_Memory + 0) + (3544*((N_Ti+1) % 2)), NextLast?2898:3542, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 3544*((N_Ti) % 2));
		KerArg0->Out = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 7088) + 3984*((N_Ti) % 2));
		KerArg0->HTileOut = (unsigned int) (Last?8:11);
		KerArg0->FirstLineIndex = (unsigned int) ((58066*Iter*11)>>16);
		rt_team_fork(gap8_ncore(), (void *) KerResizeBilinear, (void *) KerArg0);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) Out + ((Iter)*3982),
			(rt_pointerT) (HOG_L1_Memory + 7088) + (3984*(N_Ti % 2)), Last?2896:3982, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=25;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyHOG_1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 10408 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (362);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (362);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 3620, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<2; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 2); NextLast = ((Iter+2) == 2); NextNextLast = ((Iter+3) == 2);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*2896),
					(rt_pointerT) (HOG_L1_Memory + 0) + (3620*((N_Ti+1) % 2)), 3620, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 3620*((N_Ti) % 2));
		KerArg0->CellLineIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=2;
	/* Call Kernel LOC_INNER_LOOP_EPILOG */
	KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 7240) + 0);
	rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
	/* =======================Write Last Tile=========================================== */
	rt_dma_memcpy((rt_pointerT) HOGFeatures + 0,
		(rt_pointerT) (HOG_L1_Memory + 7240) + 0, 3168, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void BodyMyHOG_1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 13576 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (362);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineIndex = (uint32_t) (2);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (362);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 3620, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<31; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 31); NextLast = ((Iter+2) == 31); NextNextLast = ((Iter+3) == 31);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*2896),
					(rt_pointerT) (HOG_L1_Memory + 0) + (3620*((N_Ti+1) % 2)), 3620, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 3620*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 7240) + 3168*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) HOGFeatures + ((Iter)*3168),
			(rt_pointerT) (HOG_L1_Memory + 7240) + (3168*(N_Ti % 2)), 3168, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=31;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyWeakHOGEstim_1(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 4608 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (32);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->ColumnIndexM1 = (uint32_t) (-1);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2304, 
		3168, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<7; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 7); NextLast = ((Iter+2) == 7); NextNextLast = ((Iter+3) == 7);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2304*((N_Ti+1) % 2)), 2304, 
					3168, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2304*((N_Ti) % 2));
		KerArg0->HoGFeatColIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=7;
	/* Call Kernel LOC_EPILOG */
	rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
}

void BodyMyWeakHOGEstim_1(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 4608 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (32);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg0->HoGFeatColIndex = (uint32_t) (7);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2304, 
		3168, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<37; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 37); NextLast = ((Iter+2) == 37); NextNextLast = ((Iter+3) == 37);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2304*((N_Ti+1) % 2)), 2304, 
					3168, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2304*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		KerArg1->ColumnIndexM1 = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=37;
}

void MyResize_2(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 15288 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerResizeBilinear_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->Win = (unsigned int) (322);
	KerArg0->Hin = (unsigned int) (242);
	KerArg0->Wout = (unsigned int) (402);
	KerArg0->Hout = (unsigned int) (302);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) In+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 3220, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<28; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 28); NextLast = ((Iter+2) == 28); NextNextLast = ((Iter+3) == 28);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) In + (((52298*(Iter+1)*11)>>16)*322),
					(rt_pointerT) (HOG_L1_Memory + 0) + (3220*((N_Ti+1) % 2)), NextLast?1610:3220, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 3220*((N_Ti) % 2));
		KerArg0->Out = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 6440) + 4424*((N_Ti) % 2));
		KerArg0->HTileOut = (unsigned int) (Last?5:11);
		KerArg0->FirstLineIndex = (unsigned int) ((52298*Iter*11)>>16);
		rt_team_fork(gap8_ncore(), (void *) KerResizeBilinear, (void *) KerArg0);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) Out + ((Iter)*4422),
			(rt_pointerT) (HOG_L1_Memory + 6440) + (4424*(N_Ti % 2)), Last?2010:4422, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=28;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyHOG_2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 11568 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (402);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (402);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 4020, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<2; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 2); NextLast = ((Iter+2) == 2); NextNextLast = ((Iter+3) == 2);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*3216),
					(rt_pointerT) (HOG_L1_Memory + 0) + (4020*((N_Ti+1) % 2)), 4020, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 4020*((N_Ti) % 2));
		KerArg0->CellLineIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=2;
	/* Call Kernel LOC_INNER_LOOP_EPILOG */
	KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 8040) + 0);
	rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
	/* =======================Write Last Tile=========================================== */
	rt_dma_memcpy((rt_pointerT) HOGFeatures + 0,
		(rt_pointerT) (HOG_L1_Memory + 8040) + 0, 3528, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void BodyMyHOG_2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 15096 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (402);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineIndex = (uint32_t) (2);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (402);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 4020, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<35; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 35); NextLast = ((Iter+2) == 35); NextNextLast = ((Iter+3) == 35);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*3216),
					(rt_pointerT) (HOG_L1_Memory + 0) + (4020*((N_Ti+1) % 2)), 4020, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 4020*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 8040) + 3528*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) HOGFeatures + ((Iter)*3528),
			(rt_pointerT) (HOG_L1_Memory + 8040) + (3528*(N_Ti % 2)), 3528, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=35;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyWeakHOGEstim_2(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 5184 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (36);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->ColumnIndexM1 = (uint32_t) (-1);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2592, 
		3528, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<7; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 7); NextLast = ((Iter+2) == 7); NextNextLast = ((Iter+3) == 7);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2592*((N_Ti+1) % 2)), 2592, 
					3528, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2592*((N_Ti) % 2));
		KerArg0->HoGFeatColIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=7;
	/* Call Kernel LOC_EPILOG */
	rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
}

void BodyMyWeakHOGEstim_2(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 5184 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (36);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg0->HoGFeatColIndex = (uint32_t) (7);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2592, 
		3528, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<42; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 42); NextLast = ((Iter+2) == 42); NextNextLast = ((Iter+3) == 42);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2592*((N_Ti+1) % 2)), 2592, 
					3528, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2592*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		KerArg1->ColumnIndexM1 = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=42;
}

void MyResize_3(
		unsigned char * In,
		unsigned char * Out,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 14640 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerResizeBilinear_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->Win = (unsigned int) (322);
	KerArg0->Hin = (unsigned int) (242);
	KerArg0->Wout = (unsigned int) (442);
	KerArg0->Hout = (unsigned int) (332);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) In+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2898, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<34; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 34); NextLast = ((Iter+2) == 34); NextNextLast = ((Iter+3) == 34);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) In + (((47572*(Iter+1)*10)>>16)*322),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2900*((N_Ti+1) % 2)), NextLast?966:2898, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2900*((N_Ti) % 2));
		KerArg0->Out = (unsigned char * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 5800) + 4420*((N_Ti) % 2));
		KerArg0->HTileOut = (unsigned int) (Last?2:10);
		KerArg0->FirstLineIndex = (unsigned int) ((47572*Iter*10)>>16);
		rt_team_fork(gap8_ncore(), (void *) KerResizeBilinear, (void *) KerArg0);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) Out + ((Iter)*4420),
			(rt_pointerT) (HOG_L1_Memory + 5800) + (4420*(N_Ti % 2)), Last?884:4420, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=34;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyHOG_3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 12728 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (442);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (442);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 4420, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<2; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 2); NextLast = ((Iter+2) == 2); NextNextLast = ((Iter+3) == 2);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*3536),
					(rt_pointerT) (HOG_L1_Memory + 0) + (4420*((N_Ti+1) % 2)), 4420, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 4420*((N_Ti) % 2));
		KerArg0->CellLineIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=2;
	/* Call Kernel LOC_INNER_LOOP_EPILOG */
	KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 8840) + 0);
	rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
	/* =======================Write Last Tile=========================================== */
	rt_dma_memcpy((rt_pointerT) HOGFeatures + 0,
		(rt_pointerT) (HOG_L1_Memory + 8840) + 0, 3888, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void BodyMyHOG_3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t ** __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 16616 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	rt_dma_copy_t DmaW_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerProcessCellLine_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerProcessBlockLine_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->W = (uint32_t) (442);
	KerArg0->CellLines = (CellLines);
	KerArg0->CellLineIndex = (uint32_t) (2);
	KerArg0->CellLineCount = (uint32_t) (1);
	KerArg1->CellLines = (CellLines);
	KerArg1->W = (uint32_t) (442);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy((rt_pointerT) ImageIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 4420, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<39; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 39); NextLast = ((Iter+2) == 39); NextNextLast = ((Iter+3) == 39);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy((rt_pointerT) ImageIn + ((Iter+1)*3536),
					(rt_pointerT) (HOG_L1_Memory + 0) + (4420*((N_Ti+1) % 2)), 4420, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint8_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 4420*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessCellLine, (void *) KerArg0);
		KerArg1->HOGFeatures = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 8840) + 3888*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerProcessBlockLine, (void *) KerArg1);
		/* =======================Write Tile=========================================== */
		if (Iter) {
			rt_dma_wait(&DmaW_Evt1);
		}
		rt_dma_memcpy((rt_pointerT) HOGFeatures + ((Iter)*3888),
			(rt_pointerT) (HOG_L1_Memory + 8840) + (3888*(N_Ti % 2)), 3888, RT_DMA_DIR_LOC2EXT, 0, &DmaW_Evt1);
		/* ===================End Write Tile=========================================== */
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=39;
	/* =======================Write Last Tile=========================================== */
	rt_dma_wait(&DmaW_Evt1);
	/* ===================End Write Last Tile=========================================== */
}

void PrimeMyWeakHOGEstim_3(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 5760 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (40);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->ColumnIndexM1 = (uint32_t) (-1);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2880, 
		3888, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<7; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 7); NextLast = ((Iter+2) == 7); NextNextLast = ((Iter+3) == 7);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2880*((N_Ti+1) % 2)), 2880, 
					3888, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2880*((N_Ti) % 2));
		KerArg0->HoGFeatColIndex = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=7;
	/* Call Kernel LOC_EPILOG */
	rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
}

void BodyMyWeakHOGEstim_3(
		uint16_t * __restrict__ HoGFeatIn,
		uint16_t ** __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	/* Shared L1: 5760 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	rt_dma_copy_t DmaR_Evt1;
	int Iter;
	int Last, NextLast, NextNextLast;
	int N_Ti = 0;
	int N_TiIp = 0, InPlane, OutPlane=0;
	KerReadHoGFeatCol_ArgT S_KerArg0, *KerArg0 = &S_KerArg0;
	KerWeakEstimate_ArgT S_KerArg1, *KerArg1 = &S_KerArg1;

	/* Initialize KerArg, Kernel invariant arguments */
	KerArg0->H = (uint32_t) (40);
	KerArg0->FeatureSize = (uint32_t) (36);
	KerArg0->EstimWidth = (uint32_t) (7);
	KerArg0->HoGFeatCols = (HoGFeatCols);
	KerArg0->HoGFeatColIndex = (uint32_t) (7);
	KerArg1->HoGFeatCols = (HoGFeatCols);
	KerArg1->HEstimator = (uint32_t) (15);
	KerArg1->HFeatCols = (HFeat);
	KerArg1->FeatureSize = (uint32_t) (36);
	KerArg1->Model = (Model);
	KerArg1->ModelSize = (ModelSize);
	/* =======================Read First Tile=========================================== */
	/* Initial reads in L2, O_DB or O_BUFF */
	rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn+(0), (rt_pointerT) (HOG_L1_Memory + 0)+0, 2880, 
		3888, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
	/* ===================End Read First Tile=========================================== */
	/* Kernel Iteration Loop on Iter space */
	for (Iter=0; Iter<47; Iter++) {
		/* Loop Iteration Body on Iter space */
		/* Elaborate Last, Next_Last, Next_Next_Last */
		Last = ((Iter+1) == 47); NextLast = ((Iter+2) == 47); NextNextLast = ((Iter+3) == 47);
		/* =======================Read Next Tile=========================================== */
		rt_dma_wait(&DmaR_Evt1);
		if (!Last) {
			rt_dma_memcpy_2d((rt_pointerT) HoGFeatIn + ((Iter+1)*72),
					(rt_pointerT) (HOG_L1_Memory + 0) + (2880*((N_Ti+1) % 2)), 2880, 
					3888, 72, RT_DMA_DIR_EXT2LOC, 0, &DmaR_Evt1);
		}
		/* ===================End Read Next Tile=========================================== */
		/* Call Kernel LOC_INNER_LOOP */
		KerArg0->In = (uint16_t * __restrict__) ((rt_pointerT) (HOG_L1_Memory + 0) + 2880*((N_Ti) % 2));
		rt_team_fork(gap8_ncore(), (void *) KerReadHoGFeatCol, (void *) KerArg0);
		KerArg1->ColumnIndexM1 = (uint32_t) Iter;
		rt_team_fork(gap8_ncore(), (void *) KerWeakEstimateAllWindows, (void *) KerArg1);
		N_Ti++;
		/* End Kernel Iteration Loop on Iter space */
	}
	Iter=47;
}

void MyHOG(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker)

{
	PrimeMyHOG(
		(uint8_t *  __restrict__) (ImageIn),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyHOG(
		(uint8_t *  __restrict__) (ImageIn+OneFullBlockLineOffset),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures+OneFullHoGFeatureLineOffset),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyWeakHOGEstim(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	PrimeMyWeakHOGEstim(
		(uint16_t * __restrict__) (HoGFeatIn),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyWeakHOGEstim(
		(uint16_t * __restrict__) (HoGFeatIn+252),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyHOG_N1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker)

{
	PrimeMyHOG_N1(
		(uint8_t *  __restrict__) (ImageIn),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyHOG_N1(
		(uint8_t *  __restrict__) (ImageIn+OneFullBlockLineOffset),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures+OneFullHoGFeatureLineOffset),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyWeakHOGEstim_N1(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	PrimeMyWeakHOGEstim_N1(
		(uint16_t * __restrict__) (HoGFeatIn),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyWeakHOGEstim_N1(
		(uint16_t * __restrict__) (HoGFeatIn+252),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyHOG_N2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker)

{
	PrimeMyHOG_N2(
		(uint8_t *  __restrict__) (ImageIn),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyHOG_N2(
		(uint8_t *  __restrict__) (ImageIn+OneFullBlockLineOffset),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures+OneFullHoGFeatureLineOffset),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyWeakHOGEstim_N2(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	PrimeMyWeakHOGEstim_N2(
		(uint16_t * __restrict__) (HoGFeatIn),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyWeakHOGEstim_N2(
		(uint16_t * __restrict__) (HoGFeatIn+252),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyHOG_N3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker)

{
	PrimeMyHOG_N3(
		(uint8_t *  __restrict__) (ImageIn),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyHOG_N3(
		(uint8_t *  __restrict__) (ImageIn+OneFullBlockLineOffset),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures+OneFullHoGFeatureLineOffset),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyWeakHOGEstim_N3(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	PrimeMyWeakHOGEstim_N3(
		(uint16_t * __restrict__) (HoGFeatIn),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyWeakHOGEstim_N3(
		(uint16_t * __restrict__) (HoGFeatIn+252),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyHOG_1(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker)

{
	PrimeMyHOG_1(
		(uint8_t *  __restrict__) (ImageIn),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyHOG_1(
		(uint8_t *  __restrict__) (ImageIn+OneFullBlockLineOffset),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures+OneFullHoGFeatureLineOffset),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyWeakHOGEstim_1(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	PrimeMyWeakHOGEstim_1(
		(uint16_t * __restrict__) (HoGFeatIn),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyWeakHOGEstim_1(
		(uint16_t * __restrict__) (HoGFeatIn+252),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyHOG_2(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker)

{
	PrimeMyHOG_2(
		(uint8_t *  __restrict__) (ImageIn),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyHOG_2(
		(uint8_t *  __restrict__) (ImageIn+OneFullBlockLineOffset),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures+OneFullHoGFeatureLineOffset),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyWeakHOGEstim_2(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	PrimeMyWeakHOGEstim_2(
		(uint16_t * __restrict__) (HoGFeatIn),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyWeakHOGEstim_2(
		(uint16_t * __restrict__) (HoGFeatIn+252),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyHOG_3(
		uint8_t *  __restrict__ ImageIn,
		uint16_t **  __restrict__ CellLines,
		uint16_t *  __restrict__ HOGFeatures,
		uint32_t OneFullBlockLineOffset,
		uint32_t OneFullHoGFeatureLineOffset,
		Kernel_Exec_T *Ker)

{
	PrimeMyHOG_3(
		(uint8_t *  __restrict__) (ImageIn),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyHOG_3(
		(uint8_t *  __restrict__) (ImageIn+OneFullBlockLineOffset),
		(uint16_t ** __restrict__) (CellLines),
		(uint16_t *  __restrict__) (HOGFeatures+OneFullHoGFeatureLineOffset),
		(Kernel_Exec_T *) (Ker)
	);
}

void MyWeakHOGEstim_3(
		uint16_t *  __restrict__ HoGFeatIn,
		uint16_t **  __restrict__ HoGFeatCols,
		uint32_t HFeat,
		HoGWeakPredictorBis_T * __restrict__ Model,
		uint32_t ModelSize,
		Kernel_Exec_T *Ker)

{
	PrimeMyWeakHOGEstim_3(
		(uint16_t * __restrict__) (HoGFeatIn),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
	BodyMyWeakHOGEstim_3(
		(uint16_t * __restrict__) (HoGFeatIn+252),
		(uint16_t ** __restrict__) (HoGFeatCols),
		(uint32_t) (HFeat),
		(HoGWeakPredictorBis_T * __restrict__) (Model),
		(uint32_t) (ModelSize),
		(Kernel_Exec_T *) (Ker)
	);
}

