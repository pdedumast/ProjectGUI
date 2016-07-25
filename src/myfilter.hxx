#ifndef __itkImageFilter_hxx
#define __itkImageFilter_hxx

#include "MyFilter.h"


namespace itk
{
    
    template< class TImage>
    void MyFilter< TImage>
    ::GenerateData()
    {
        
        typename TImage::ConstPointer input = this->GetInput();
        typename TImage::Pointer output = this->GetOutput();
        
        this->AllocateOutputs();
        
        
        // Type of usefull iterators
        typedef itk::ConstNeighborhoodIterator< TImage > NeighborhoodIteratorType;
        typedef itk::ImageRegionIterator< TImage>        IteratorType;
        
        // Define size of NeighborhoodIterator
        typename NeighborhoodIteratorType::RadiusType radius;
        radius.Fill(1);
        
        // Create the iterator on the requested region of the input image
        NeighborhoodIteratorType it( radius, input,
                                    input->GetRequestedRegion() );
        
        // Create the iterator on the requested region of the input image
        output->SetRegions(input->GetRequestedRegion());
        output->Allocate();
        IteratorType out(output, input->GetRequestedRegion());
        
        
        // Necessary neighborhood positions (v8 neighborhood)
        typename NeighborhoodIteratorType::OffsetType offset1 = {{-1,-1}};
        typename NeighborhoodIteratorType::OffsetType offset2 = {{0,-1}};
        typename NeighborhoodIteratorType::OffsetType offset3 = {{1,-1}};
        typename NeighborhoodIteratorType::OffsetType offset4 = {{-1,0 }};
        typename NeighborhoodIteratorType::OffsetType offset5 = {{1,0}};
        typename NeighborhoodIteratorType::OffsetType offset6 = {{-1,1}};
        typename NeighborhoodIteratorType::OffsetType offset7 = {{0,1}};
        typename NeighborhoodIteratorType::OffsetType offset8 = {{1,1}};
        
        
        // Compute mean of center pixel's neighborhoods
        for (it.GoToBegin(), out.GoToBegin(); !it.IsAtEnd(); ++it, ++out)
        {
            float sum;
            
            sum = it.GetPixel(offset1) + it.GetPixel(offset2)
            + it.GetPixel(offset3) + it.GetPixel(offset4)
            + it.GetPixel(offset5) + it.GetPixel(offset6)
            + it.GetPixel(offset7) + it.GetPixel(offset8);
            
            sum /= 8.0f;
            out.Set(sum);
        }
        
        
        
        
        
        
        
    }
    
}// end namespace


#endif