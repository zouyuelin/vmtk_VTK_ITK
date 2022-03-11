/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkAsinImageAdaptor_h
#define itkAsinImageAdaptor_h

#include "itkImageAdaptor.h"
#include "itkMath.h"

namespace itk
{
namespace Accessor
{
/**
 * \class AsinPixelAccessor
 * \brief Give access to the std::asin() function of a value
 *
 * AsinPixelAccessor is templated over an internal type and an
 * external type representation. This class cast the input
 * applies the function to it and cast the result according
 * to the types defined as template parameters
 *
 * \ingroup ImageAdaptors
 * \ingroup ITKImageAdaptors
 */
template< typename TInternalType, typename TExternalType >
class AsinPixelAccessor
{
public:

  /** External typedef. It defines the external aspect
   *  that this class will exhibit. */
  typedef TExternalType ExternalType;

  /** Internal typedef. It defines the internal real
   * representation of data. */
  typedef TInternalType InternalType;

  static inline void Set(TInternalType & output, const TExternalType & input)
  { output = (TInternalType)std::asin( (double)input ); }

  static inline TExternalType Get(const TInternalType & input)
  { return (TExternalType)std::asin( (double)input ); }
};
} // end namespace Accessor

/**
 * \class AsinImageAdaptor
 * \brief Presents an image as being composed of the std::asin() of its pixels
 *
 * Additional casting is performed according to the input and output image
 * types following C++ default casting rules.
 *
 * \ingroup ImageAdaptors
 * \ingroup ITKImageAdaptors
 */
template< typename TImage, typename TOutputPixelType >
class AsinImageAdaptor:public
  ImageAdaptor< TImage,
                Accessor::AsinPixelAccessor<
                  typename TImage::PixelType,
                  TOutputPixelType >   >
{
public:
  /** Standard class typedefs. */
  typedef AsinImageAdaptor Self;
  typedef ImageAdaptor< TImage,
                        Accessor::AsinPixelAccessor< typename TImage::PixelType, TOutputPixelType > > Superclass;

  typedef SmartPointer< Self >       Pointer;
  typedef SmartPointer< const Self > ConstPointer;

  /** Run-time type information (and related methods). */
  itkTypeMacro(AsinImageAdaptor, ImageAdaptor);

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

protected:
  AsinImageAdaptor() {}
  virtual ~AsinImageAdaptor() ITK_OVERRIDE {}

private:
  ITK_DISALLOW_COPY_AND_ASSIGN(AsinImageAdaptor);
};
} // end namespace itk

#endif
