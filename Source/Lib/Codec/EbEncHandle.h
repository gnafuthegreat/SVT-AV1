/*
* Copyright(c) 2019 Intel Corporation
* SPDX - License - Identifier: BSD - 2 - Clause - Patent
*/

#ifndef EbEncHandle_h
#define EbEncHandle_h

#include "EbDefinitions.h"
#include "EbApi.h"
#include "EbPictureBufferDesc.h"
#include "EbSystemResourceManager.h"
#include "EbSequenceControlSet.h"

#include "EbResourceCoordinationResults.h"
#include "EbPictureDemuxResults.h"
#include "EbRateControlResults.h"

/**************************************
 * Component Private Data
 **************************************/
typedef struct EbEncHandle_s
{
    // Encode Instances & Compute Segments
    uint32_t                                  encodeInstanceTotalCount;
    uint32_t                                 *computeSegmentsTotalCountArray;

    // Config Set Counts
    uint32_t                                  sequenceControlSetPoolTotalCount;

    // Full Results Count
    uint32_t                                  pictureControlSetPoolTotalCount;

    // Picture Buffer Counts
    uint32_t                                  reconPicturePoolTotalCount;
    uint32_t                                  coeffPicturePoolTotalCount;
    uint32_t                                  referencePicturePoolTotalCount;
    uint32_t                                  paReferencePicturPooleBufferInitCount;

    // Config Set Pool & Active Array
    EbSystemResource_t                     *sequenceControlSetPoolPtr;
    EbFifo_t                              **sequenceControlSetPoolProducerFifoPtrArray;
    EbSequenceControlSetInstance_t        **sequenceControlSetInstanceArray;

    // Full Results
    EbSystemResource_t                    **pictureControlSetPoolPtrArray;
    EbFifo_t                             ***pictureControlSetPoolProducerFifoPtrDblArray;

    //ParentControlSet
    EbSystemResource_t                    **pictureParentControlSetPoolPtrArray;
    EbFifo_t                             ***pictureParentControlSetPoolProducerFifoPtrDblArray;

    // Picture Buffers
    EbSystemResource_t                    **referencePicturePoolPtrArray;
    EbSystemResource_t                    **paReferencePicturePoolPtrArray;

    // Picture Buffer Producer Fifos
    EbFifo_t                             ***referencePicturePoolProducerFifoPtrDblArray;
    EbFifo_t                             ***paReferencePicturePoolProducerFifoPtrDblArray;

    // Thread Handles
    EbHandle                               resourceCoordinationThreadHandle;
    EbHandle                               pictureEnhancementThreadHandle;
    EbHandle                              *pictureAnalysisThreadHandleArray;
    EbHandle                               pictureDecisionThreadHandle;
    EbHandle                              *motionEstimationThreadHandleArray;
    EbHandle                               initialRateControlThreadHandle;
    EbHandle                              *sourceBasedOperationsThreadHandleArray;
    EbHandle                               pictureManagerThreadHandle;
    EbHandle                               rateControlThreadHandle;
    EbHandle                              *modeDecisionConfigurationThreadHandleArray;
    EbHandle                              *encDecThreadHandleArray;
    EbHandle                              *entropyCodingThreadHandleArray;
    EbHandle                               packetizationThreadHandle;

    // Contexts
    EbPtr                                  resourceCoordinationContextPtr;
    EbPtr                                  pictureEnhancementContextPtr;
    EbPtr                                 *pictureAnalysisContextPtrArray;
    EbPtr                                  pictureDecisionContextPtr;
    EbPtr                                 *motionEstimationContextPtrArray;
    EbPtr                                  initialRateControlContextPtr;
    EbPtr                                 *sourceBasedOperationsContextPtrArray;
    EbPtr                                  pictureManagerContextPtr;
    EbPtr                                  rateControlContextPtr;
    EbPtr                                 *modeDecisionConfigurationContextPtrArray;
    EbPtr                                 *encDecContextPtrArray;
    EbPtr                                 *entropyCodingContextPtrArray;
    EbPtr                                  packetizationContextPtr;

    // System Resource Managers
    EbSystemResource_t                     *input_buffer_resource_ptr;
    EbSystemResource_t                    **output_stream_buffer_resource_ptr_array;
    EbSystemResource_t                    **output_recon_buffer_resource_ptr_array;
    EbSystemResource_t                    **output_statistics_buffer_resource_ptr_array;
    EbSystemResource_t                     *resourceCoordinationResultsResourcePtr;
    EbSystemResource_t                     *pictureAnalysisResultsResourcePtr;
    EbSystemResource_t                     *pictureDecisionResultsResourcePtr;
    EbSystemResource_t                     *motionEstimationResultsResourcePtr;
    EbSystemResource_t                     *initialRateControlResultsResourcePtr;
    EbSystemResource_t                     *pictureDemuxResultsResourcePtr;
    EbSystemResource_t                     *rateControlTasksResourcePtr;
    EbSystemResource_t                     *rateControlResultsResourcePtr;
    EbSystemResource_t                     *encDecTasksResourcePtr;
    EbSystemResource_t                     *encDecResultsResourcePtr;
    EbSystemResource_t                     *entropyCodingResultsResourcePtr;

    // Inter-Process Producer Fifos
    EbFifo_t                              **input_buffer_producer_fifo_ptr_array;
    EbFifo_t                             ***output_stream_buffer_producer_fifo_ptr_dbl_array;
    EbFifo_t                             ***output_recon_buffer_producer_fifo_ptr_dbl_array;
    EbFifo_t                             ***output_statistics_buffer_producer_fifo_ptr_dbl_array;
    EbFifo_t                              **resourceCoordinationResultsProducerFifoPtrArray;
    EbFifo_t                              **pictureAnalysisResultsProducerFifoPtrArray;
    EbFifo_t                              **pictureDecisionResultsProducerFifoPtrArray;
    EbFifo_t                              **motionEstimationResultsProducerFifoPtrArray;
    EbFifo_t                              **initialRateControlResultsProducerFifoPtrArray;
    EbFifo_t                              **pictureDemuxResultsProducerFifoPtrArray;
    EbFifo_t                              **pictureManagerResultsProducerFifoPtrArray;
    EbFifo_t                              **rateControlTasksProducerFifoPtrArray;
    EbFifo_t                              **rateControlResultsProducerFifoPtrArray;
    EbFifo_t                              **encDecTasksProducerFifoPtrArray;
    EbFifo_t                              **encDecResultsProducerFifoPtrArray;
    EbFifo_t                              **entropyCodingResultsProducerFifoPtrArray;

    // Inter-Process Consumer Fifos
    EbFifo_t                              **input_buffer_consumer_fifo_ptr_array;
    EbFifo_t                             ***output_stream_buffer_consumer_fifo_ptr_dbl_array;
    EbFifo_t                             ***output_recon_buffer_consumer_fifo_ptr_dbl_array;
    EbFifo_t                             ***output_statistics_buffer_consumer_fifo_ptr_dbl_array;
    EbFifo_t                              **resourceCoordinationResultsConsumerFifoPtrArray;
    EbFifo_t                              **pictureAnalysisResultsConsumerFifoPtrArray;
    EbFifo_t                              **pictureDecisionResultsConsumerFifoPtrArray;
    EbFifo_t                              **motionEstimationResultsConsumerFifoPtrArray;
    EbFifo_t                              **initialRateControlResultsConsumerFifoPtrArray;
    EbFifo_t                              **pictureDemuxResultsConsumerFifoPtrArray;
    EbFifo_t                              **rateControlTasksConsumerFifoPtrArray;
    EbFifo_t                              **rateControlResultsConsumerFifoPtrArray;
    EbFifo_t                              **encDecTasksConsumerFifoPtrArray;
    EbFifo_t                              **encDecResultsConsumerFifoPtrArray;
    EbFifo_t                              **entropyCodingResultsConsumerFifoPtrArray;

    // Callbacks
    EbCallback_t                          **app_callback_ptr_array;

    // Memory Map
    EbMemoryMapEntry                       *memoryMap;
    uint32_t                                memoryMapIndex;
    uint64_t                                totalLibMemory;

} EbEncHandle_t;


#endif // EbEncHandle_h