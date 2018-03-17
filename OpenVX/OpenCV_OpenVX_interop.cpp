// Copyright (2016) Intel Corporation.
// 
// The source code, information and material ("Material") contained herein is
// owned by Intel Corporation or its suppliers or licensors, and title to
// such Material remains with Intel Corporation or its suppliers or licensors.
// The Material contains proprietary information of Intel or its suppliers and
// licensors. The Material is protected by worldwide copyright laws and treaty
// provisions. No part of the Material may be used, copied, reproduced, modified,
// published, uploaded, posted, transmitted, distributed or disclosed in any
// way without Intel's prior express written permission. No license under any
// patent, copyright or other intellectual property rights in the Material is
// granted to or conferred upon you, either expressly, by implication,
// inducement, estoppel or otherwise. Any license under such intellectual
// property rights must be express and approved by Intel in writing.
//
// Unless otherwise agreed by Intel in writing, you may not remove or alter
// this notice or any other notice embedded in Materials by Intel or Intel's
// suppliers or licensors in any way.

#include <string>
#include <intel/vx_samples/helper.hpp>
#include <intel/vx_samples/cmdparser.hpp>
#include <intel/vx_samples/perfprof.hpp>
#include <opencv2/opencv.hpp>
using namespace std;
//=====================================================
class CmdParserAutoContrast: public CmdParserWithHelp
{
public:
    CmdParserAutoContrast(int argc, const char** argv) : CmdParser(argc, argv), CmdParserWithHelp(argc, argv),
        input(
            *this,
            'i',
            "input",
            "<file name>",
            "Input image file.",
            "./low_contrast_vga.jpg"
            ),
        output(*this),
        as_gray(
            *this,
            'g',
            "gray",
            "read image as gray-scale",
            "Read image file in gray-scale (single channel).",
            false
            ),
        noshow(*this),
        loops(
            *this,
            'l',
            "loops",
            "numbers of times the grap is looped",
            "Numbers of times the same graph is esxecuted in a loop.",
            1
            )
    {
    }
    CmdOption<std::string> input;
    CmdOptionOutputImage output;
    CmdOption<bool> as_gray;
    CmdOptionNoShow noshow;
    CmdOption<unsigned int> loops;

    virtual void parse()
    {
        CmdParserWithHelp::parse();
        if (input.getValue().empty())
        {
            throw CmdParser::Error("Input file name is required. Use --input FILE to provide input video file name.");
        }

    }
};
//=====================================================
PERFPROF_REGION_DEFINE(vxProcessGraph);
//=====================================================
vx_image cv_to_vx(const cv::Mat& src, const vx_context& context, vx_imagepatch_addressing_t& frameFormat, int inputChannels)
{
    void* frameData = src.data;

    //creating input image, by wrapping the host side pointer (e.g. when the frame comes from OpenCV)
    vx_image imageOrig = vxCreateImageFromHandle(
        context,
        (1==inputChannels) ? VX_DF_IMAGE_U8 : VX_DF_IMAGE_RGB,
        &frameFormat,
        &frameData,
        VX_MEMORY_TYPE_HOST
        );

    //// Store vector of vx_image's
    //vximages.push_back(imageOrig);

    return imageOrig;
}
//=====================================================
void vx_to_cv()
{}
//=====================================================
int main(int argc, const char* argv[])
{
    std::cout << "\n\nJosh - Begin OpenVX Code:\n\n";
    
    // Profile loop:
    for (int i = 0; i < 100; ++i)
    {
    try
        {
            // Parse command line arguments.
            // See CmdParserVideoStabilization for command line knobs description.
            CmdParserAutoContrast cmdparser(argc, argv);
            cmdparser.parse();

            if (cmdparser.help.isSet())
            {
                // Immediatly exit if user wanted to see the usage information only.
                return 0;
            }

            /***************OpenVX init************************/
            vx_status status = VX_SUCCESS;

            // Create context:
            // Create context:
            // Create context:
            // Create context:
            vx_context context = vxCreateContext();
            status = vxGetStatus((vx_reference)context);
            CHECK_VX_STATUS(status);

            vxRegisterLogCallback(context, IntelVXSample::errorReceiver, vx_true_e);
            
            // Create Graph:
            // Create Graph:
            // Create Graph:            
            // Create Graph:
            vx_graph graph = vxCreateGraph(context);
            status = vxGetStatus((vx_reference)graph);
            CHECK_VX_STATUS(status);
            
            // a vector for OpenVX nodes (merely for resource clean-up purposes)
            std::vector<vx_node> vxnodes;
            // a vector for OpenVX images (merely for resource clean-up purposes)
            std::vector<vx_image> vximages;
            /***************\OpenVX init************************/

            /***************inputs and outputs ************************/
            int inputWidth, inputHeight;
            int inputChannels = cmdparser.as_gray.getValue() ? 1 : 3;

            std::cout << "AT OPENCV POINT - JOSH!\n\n\n\n";

            // READ DATA USING OpenCV
            // READ DATA USING OpenCV
            // READ DATA USING OpenCV
            // READ DATA USING OpenCV
            std::cerr << "[ INFO ] Reading input file using OpenCV file I/O" << cmdparser.input.getValue() << endl;
            cv::Mat src = cv::imread(cmdparser.input.getValue(), cmdparser.as_gray.getValue() ? CV_LOAD_IMAGE_GRAYSCALE : CV_LOAD_IMAGE_UNCHANGED);
            if(!src.data)
            {
                std::cerr << "[ ERROR ] cannot read input file\n";
                std::exit(1);
            }

            // Grad dimensions of image
            inputWidth = src.size().width;
            inputHeight = src.size().height;
            inputChannels = src.channels();
            std::cerr << "[ INFO ] Input file ok: " << inputWidth <<"x"<<inputHeight << " and "<< inputChannels<<" channel(s)"<<endl;

            // CONSTRUCT DATA STRUCTURE TO STORE IMAGE FOR OPEN-VX PROCESSING
            // CONSTRUCT DATA STRUCTURE TO STORE IMAGE FOR OPEN-VX PROCESSING
            // CONSTRUCT DATA STRUCTURE TO STORE IMAGE FOR OPEN-VX PROCESSING
            // CONSTRUCT DATA STRUCTURE TO STORE IMAGE FOR OPEN-VX PROCESSING

            //structure used by the host to address image pixels
            vx_imagepatch_addressing_t frameFormat;

            //dimension in x, in pixels
            frameFormat.dim_x = src.cols;

            //dimension in y, in pixels
            frameFormat.dim_y = src.rows;

            //distance (in bytes) from a pixel to the next adjacent pixel in the positive x direction
            frameFormat.stride_x = (vx_uint32)src.elemSize();

            //distance (in bytes) from a pixel to the next adjacent pixel in the positive y direction
            frameFormat.stride_y = (vx_uint32)src.step;

            //scaling from the primary plane (zero indexed plane) to this plane (relevant only to the multi-plane images)
            frameFormat.scale_x = VX_SCALE_UNITY;
            frameFormat.scale_y = VX_SCALE_UNITY;

            //number of pixels to skip to arrive at the next pixel (relevant only to the multi-plane images)
            //e.g. on a plane that is half-scaled, the step of 2 would indicate that every other pixel is an alias
            frameFormat.step_x = 1;
            frameFormat.step_y = 1;

            // COPY DATA FROM OPEN-CV INTO OPEN-VX OBJECT (vx_image class)
            // COPY DATA FROM OPEN-CV INTO OPEN-VX OBJECT
            // COPY DATA FROM OPEN-CV INTO OPEN-VX OBJECT
            // COPY DATA FROM OPEN-CV INTO OPEN-VX OBJECT

            // Input:  cv::Mat
            // Output: 

            void* frameData = src.data;

            //creating input image, by wrapping the host side pointer (e.g. when the frame comes from OpenCV)
            /*
            vx_image imageOrig = vxCreateImageFromHandle(
                context,
                (1==inputChannels) ? VX_DF_IMAGE_U8 : VX_DF_IMAGE_RGB,
                &frameFormat,
                &frameData,
                VX_MEMORY_TYPE_HOST
                );
            vximages.push_back(imageOrig);
            */

            vx_image imageOrig = cv_to_vx(src, context, frameFormat, inputChannels);

            // JOSH     
            // JOSH     
            // JOSH 
            // Copy data from Open-VX to Open-CV

            // vx_image can be accessed with OpenCV, using these functions:
                //vxMapImagePatch
                //vxUnmapImagePatch
            // (see the Example Interoperability with OpenCV section).
            //callOpenCVGaussianBlur(vx_image input, vx_image output)

            //vx_image newVX_image_josh;
            //callOpenCVGaussianBlur(imageOrig, newVX_image_josh);

            // imagOrig -> (Guassian Blur in Open-CV) -> newVX_image_josh



            // ALLOCATE SPACE FOR OUTPUT OPEN-VX DATA OBJECT
            // ALLOCATE SPACE FOR OUTPUT OPEN-VX DATA OBJECT
            // ALLOCATE SPACE FOR OUTPUT OPEN-VX DATA OBJECT
            // ALLOCATE SPACE FOR OUTPUT OPEN-VX DATA OBJECT

            //creating output image, which matches the input
            vx_image imageRes = vxCreateImage(context, inputWidth, inputHeight, (inputChannels== 1) ? VX_DF_IMAGE_U8 : VX_DF_IMAGE_RGB);
            if (imageOrig == NULL || imageRes == NULL)
            {
                std::cerr << "[ ERROR ] cannot create input/output images\n";
                std::exit(1);
            }
            vximages.push_back(imageRes);
            /***************\inputs and outputs ************************/



            /***************actual graph machinery************************/
            /***************actual graph machinery************************/
            /***************actual graph machinery************************/
            /***************actual graph machinery************************/
            /***************actual graph machinery************************/
            /***************actual graph machinery************************/
            /***************actual graph machinery************************/
            if (3 == inputChannels)
            {
                //a virtual image that will store the results of input image conversion into the NV12 format
                vx_image imageNV12 = vxCreateVirtualImage(graph, inputWidth, inputHeight, VX_DF_IMAGE_NV12);
                vximages.push_back(imageNV12);
                //a virtual image that will store the results of image processing (in the NV12 format)
                vx_image imageNV12Eq     = vxCreateVirtualImage(graph, inputWidth, inputHeight, VX_DF_IMAGE_NV12);
                vximages.push_back(imageNV12Eq);

                //a separate virtual image to store extracted Y plane, for processing            
                vx_image imageChannelY  = vxCreateVirtualImage(graph, inputWidth, inputHeight, VX_DF_IMAGE_U8);
                vximages.push_back(imageChannelY);
                //a separate virtual image to store results of processing the Y plane            
                vx_image imageChannelYEq = vxCreateVirtualImage(graph, inputWidth, inputHeight, VX_DF_IMAGE_U8);
                vximages.push_back(imageChannelYEq);
                //a separate virtual image to store extracted U plane, left intact            
                vx_image imageU = vxCreateVirtualImage(graph, inputWidth / 2, inputHeight / 2, VX_DF_IMAGE_U8);
                vximages.push_back(imageU);
            //a separate virtual image to store extracted V plane, left intact            
                vx_image imageV = vxCreateVirtualImage(graph, inputWidth / 2, inputHeight / 2, VX_DF_IMAGE_U8);
                vximages.push_back(imageV);
                /*********************************************************************************************
                                             >|channel extract|->Y->|equalize_hist|--
                                            /                                        \
                RGB (input)->|convert|->NV12->|channel extract|->U------------------ ->|convert|->RGB (output)
                                            \                                        /
                                            >|channel extract|->V-------------------  
                *********************************************************************************************/
                vxnodes.push_back(
                    vxColorConvertNode(graph, imageOrig, imageNV12));
                vxnodes.push_back(
                    vxChannelExtractNode(graph, imageNV12, VX_CHANNEL_Y, imageChannelY));
                vxnodes.push_back(
                    vxEqualizeHistNode(graph, imageChannelY, imageChannelYEq));
                vxnodes.push_back(
                    vxChannelExtractNode(graph, imageNV12, VX_CHANNEL_U, imageU));
                vxnodes.push_back(
                    vxChannelExtractNode(graph, imageNV12, VX_CHANNEL_V, imageV));
                vxnodes.push_back(
                    vxChannelCombineNode(graph, imageChannelYEq, imageU, imageV, 0, imageNV12Eq));
                vxnodes.push_back(
                    vxColorConvertNode(graph, imageNV12Eq, imageRes));
            }
            else
            {
                vxnodes.push_back(
                    vxEqualizeHistNode(graph, imageOrig, imageRes));
            }

            status = vxVerifyGraph(graph);
            CHECK_VX_STATUS(status);
            std::cerr << "[ INFO ] Verifying the graph: OK " << graph << "\n";
            const unsigned int loops = cmdparser.loops.getValue();
            //looping the same graph to measure the performance more accurately ( e.g. by averaging the time)
            for (unsigned int i = 0; i < loops; i++)
            {
                PERFPROF_REGION_BEGIN(vxProcessGraph);
                status = vxProcessGraph(graph);
                PERFPROF_REGION_END(vxProcessGraph);
                CHECK_VX_STATUS(status);
            }
            std::cerr << "[ INFO ] Graph execution is OK " << graph << "\n";
            /***************\actual graph machinery ************************/

            /*************** saving and displaying the results************************/

            // COPY OPEN-VX DATA INTO OPEN-CV MAT OBJECT
            // COPY OPEN-VX DATA INTO OPEN-CV MAT OBJECT
            // COPY OPEN-VX DATA INTO OPEN-CV MAT OBJECT
            // COPY OPEN-VX DATA INTO OPEN-CV MAT OBJECT
            vx_map_id map_id;
            cv::Mat res = IntelVXSample::mapAsMat(imageRes, VX_READ_ONLY, &map_id);
            if (cmdparser.output.isSet())
            {
                cv::imwrite(cmdparser.output.getValue(), res);
            }

            // DISPLAY IMAGES - turn off to profile.
            // DISPLAY IMAGES - turn off to profile.
            // DISPLAY IMAGES - turn off to profile.
            // DISPLAY IMAGES - turn off to profile.
            if(!cmdparser.noshow.isSet())
            {
                cv::imshow("Input image", src);
                cv::imshow("Processed image:", res);
                cv::waitKey(0);
            }
            IntelVXSample::unmapAsMat(imageRes,res,map_id);

            /***************\saving and displaying the results************************/

            /*************** clean-up ************************/
            for (int n = 0; n < vxnodes.size(); n++)
            {
                //release each node
                status = vxReleaseNode(&vxnodes[n]);
                CHECK_VX_STATUS(status)
            }
            for (int n = 0; n < vximages.size(); n++)
            {
                //release each image
                status = vxReleaseImage(&vximages[n]);
                CHECK_VX_STATUS(status)
            }
            //release graph
            status = vxReleaseGraph(&graph);
            CHECK_VX_STATUS(status)
            //release context
            status = vxReleaseContext(&context);
            CHECK_VX_STATUS(status)
            /*************** \clean-up ************************/

            printf("End of execution\n");
            return 0;
        }
        /***************\ saving and displaying the results************************/
        catch (const CmdParser::Error& error)
        {
            cerr
                << "[ ERROR ] In command line: " << error.what() << "\n"
                << "Run " << argv[0] << " -h for usage info.\n";
            return 1;
        }
        catch (const std::exception& error)
        {
            cerr << "[ ERROR ] " << error.what() << "\n";
            return 1;
        }
        catch (...)
        {
            cerr << "[ ERROR ] Unknown/internal exception happened.\n";
            return 1;
        }
    } // End profile-loop (josh)
    
}
