#
# Be sure to run `pod lib lint SFLiveManager.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'SFLiveManager'
  s.version          = '0.1.6'
  s.summary          = 'A short description of SFLiveManager.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/Joygo-Technology/SFLiveManager'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'lee' => 'nemoleo@yeah.net' }
  s.source           = { :git => 'https://github.com/Joygo-Technology/SFLiveManager.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'SFLiveManager/Classes/**/*.h'
  
  # s.resource_bundles = {
  #   'SFLiveManager' => ['SFLiveManager/Assets/*.png']
  # }

  s.public_header_files = 'SFLiveManager/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'

  s.preserve_paths = 'ffmpeg/include/*.h','openssl/include/*.h','osl/include/*.h'
  s.vendored_libraries = 'SFLiveManager/Library/**/*.a','osl/*.a','openssl/libs/*.a','ffmpeg/lib/*.a'

  s.frameworks = 'Foundation','AVFoundation','VideoToolbox','AudioToolbox','CoreTelephony','OpenAL','UIKit','CoreMotion'
  s.libraries = 'stdc++','c++','iconv','resolv'

  s.pod_target_xcconfig = { 
    'ENABLE_BITCODE' => 'NO' 
  }

  s.user_target_xcconfig = {
       'CLANG_CXX_LANGUAGE_STANDARD' => 'c++11',
       'CLANG_CXX_LIBRARY' => 'libc++',
       'HEADER_SEARCH_PATHS' => "${PODS_ROOT}/#{s.name}/ffmpeg/include ${PODS_ROOT}/#{s.name}/osl/include ${PODS_ROOT}/#{s.name}/openssl/include"
  }

end
