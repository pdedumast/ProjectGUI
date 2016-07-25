#ifndef __itkImageFilter_h
#define __itkImageFilter_h

#include "itkImageToImageFilter.h"
#include "itkObjectFactory.h"
#include "itkImageRegionIterator.h"
#include "itkImageRegionConstIterator.h"
#include "itkConstNeighborhoodIterator.h"



namespace itk
{
    template< class TImage>
    class MyFilter:public ImageToImageFilter< TImage, TImage >
    {
    public:
        /** Standard class typedefs. */
        typedef MyFilter             Self;
        typedef ImageToImageFilter< TImage, TImage > Superclass;
        typedef SmartPointer< Self >        Pointer;
        
        /** Method for creation through the object factory. */
        itkNewMacro(Self);
        
        /** Run-time type information (and related methods). */
        itkTypeMacro(MyFilter, ImageToImageFilter);
        
    protected:
        MyFilter(){}
        ~MyFilter(){}
        
        /** Does the real work. */
        virtual void GenerateData()ITK_OVERRIDE;
        
        /** MyFilter function. */
        void MyFilterFunction();
        
    private:
        MyFilter(const Self &); //purposely not implemented
        void operator=(const Self &);  //purposely not implemented
        
    };
} //namespace ITK


#ifndef ITK_MANUAL_INSTANTIATION
#include "MyFilter.hxx"
#endif


#endif // __itkImageFilter_h
