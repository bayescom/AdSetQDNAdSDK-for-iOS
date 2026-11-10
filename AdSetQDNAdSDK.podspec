Pod::Spec.new do |s|
  s.name             = 'AdSetQDNAdSDK'
  s.version          = '5.0.1'
  s.summary          = 'A short description of AdSetQDNAdSDK'
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC
  
  s.homepage         = 'https://github.com/bayescom/AdSetQDNAdSDK-for-iOS.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'guangyao' => 'wangguangyao@163.com' }
  s.source           = { :git => 'git@github.com:bayescom/AdSetQDNAdSDK-for-iOS.git', :tag => s.version.to_s }

  s.platform     = :ios, "10.0"
  s.frameworks   = 'StoreKit', 'CoreTelephony', 'AdSupport', 'SystemConfiguration', 'AVFoundation'
  s.vendored_frameworks = 'AdSetQDNAdSDK/*.xcframework'
   
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
  #s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.xcconfig = {
          'OTHER_LDFLAGS' => '-ObjC'
      }
  
end
