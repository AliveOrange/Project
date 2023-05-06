import matplotlib.pyplot as plt
import palettable 
from numpy import sort
import numpy as np
from pyproj import Transformer

def getCoeffs(coeffs, start_idx):
  res = [round(float(coeffs[start_idx + 0]), 3),
         round(float(coeffs[start_idx + 1]), 5),
         round(float(coeffs[start_idx + 2]), 7),
         round(float(coeffs[start_idx + 3]), 9),
         round(float(coeffs[start_idx + 4]), 3),
         round(float(coeffs[start_idx + 5]), 3),
         round(float(coeffs[start_idx + 6]), 3)]
  return res


def get2SigmaValue(coeffs,sigma):
  coeffs = np.array(coeffs)
  Nsigma = np.percentile(coeffs, (sigma)*100, axis=0)
  Psigma = np.percentile(coeffs, (1-sigma)*100, axis=0)
  return Nsigma, Psigma


def plotLineCoeffs(timestamps, coeffs, save_pic_name):
  fig, axes = plt.subplots(7, 1, sharex=True, sharey=False, figsize=(15,15))
 
  for i, row in enumerate(axes):
    row.scatter(timestamps, [c[i] for c in coeffs], s=5, color='red', label='perc')
  
  Nsigma , Psigma = get2SigmaValue(coeffs, sigma)
  sigma_c0 = round(Nsigma[0],4)
  sigma1_c0 = round(Psigma[0],4)
  sigma_c1 = round(Nsigma[1],4)
  sigma1_c1 = round(Psigma[1],4)

  fig.text(0.45, 0.99, save_pic_name.split(".")[0], fontsize=20, va='center')
  fig.text(0.9, 0, 'timestamp', ha='center')
  fig.text(0, 0.98, 'c0', va='center')
  fig.text(0.06, 6.15 / 7.0, 'sigma_c0 = '+ str(sigma_c0) + '  sigma1_c0 = ' + str(sigma1_c0), va='center')
  fig.text(0, 6.0 / 7.0, 'c1', va='center')
  fig.text(0.06, 5.15/ 7.0, 'sigma_c1 = '+ str(sigma_c1) + '  sigma1_c1 = ' + str(sigma1_c1), va='center')
  fig.text(0, 5.0 / 7.0, 'c2', va='center')
  fig.text(0, 4.0 / 7.0, 'c3', va='center')
  fig.text(0, 3.0 / 7.0, 'x0', va='center')
  fig.text(0, 2.0 / 7.0, 'x1', va='center')
  fig.text(0, 1.0 / 7.0, 'confidence', va='center')
  plt.legend()     
  plt.tight_layout()
  plt.savefig(save_pic_name, bbox_inches='tight')
  plt.cla()


def plotDiffCoeffs(timestamps, coeffs, save_pic_name):

  fig, axes = plt.subplots(7, 1, sharex=True, sharey=False, figsize=(15,15))
 
  for i, row in enumerate(axes):
    row.scatter(timestamps, [c[i] for c in coeffs], s=5, color='red', label='perc')
  
  Nsigma , Psigma = get2SigmaValue(coeffs, sigma)
  sigma_diff_c0 = round(Nsigma[0],4)
  sigma1_diff_c0 = round(Psigma[0],4)
  sigma_diff_c1 = round(Nsigma[1],4)
  sigma1_diff_c1 = round(Psigma[1],4)

  fig.text(0.45, 0.99, save_pic_name.split(".")[0], fontsize=20, va='center')
  fig.text(0.5, 0.02, 'timestamp', ha='center')
  fig.text(0, 0.98, 'diff_c0', va='center')
  fig.text(0.06, 6.15 / 7.0, 'sigma_c0 = '+ str(sigma_diff_c0) + '  sigma1_c0 = ' + str(sigma1_diff_c0), va='center')
  fig.text(0, 6.0 / 7.0, 'c1', va='center')
  fig.text(0.06, 5.15/ 7.0, 'sigma_c1 = '+ str(sigma_diff_c1) + '  sigma1_c1 = ' + str(sigma1_diff_c1), va='center')
  fig.text(0, 5.0 / 7.0, 'diff_c2', va='center')
  fig.text(0, 4.0 / 7.0, 'diff_c3', va='center')
  fig.text(0, 3.0 / 7.0, 'diff_x0', va='center')
  fig.text(0, 2.0 / 7.0, 'diff_x1', va='center')
  fig.text(0, 1.0 / 7.0, 'x1-x0', va='center')
  plt.legend()     
  plt.tight_layout()
  plt.savefig(save_pic_name, bbox_inches='tight')
  plt.cla()


def plotTimeStampDiff(timestamps, timestamp2s, save_pic_name):

  diff_timestamps = []
  diff_timestamp2s = []

  for i in range(1,len(timestamps)):
    if timestamps[i] != 0 and timestamps[i-1] != 0:
      diff_timestamps.append(timestamps[i]/1000-timestamps[i-1]/1000)

    if timestamp2s[i] != 0 and timestamp2s[i-1] != 0:
      diff_timestamp2s.append(timestamp2s[i]/1000-timestamp2s[i-1]/1000)
  
  # print('相机时间戳帧差',diff_timestamps)

  j = 0
  for each in diff_timestamps:
    if each >= 30 and each <= 66:
      j = j+1
  percent_timestamps = str(round(j/len(diff_timestamps)*100,2)) + '%'                  # 统计接受信号帧时间差分布
  Max_diff_timestamps = round(max(diff_timestamps),2)
  Min_diff_timestamps = round(min(diff_timestamps),2)

  j = 0
  for each in diff_timestamp2s:
    if each >= 30 and each <= 66:
      j = j+1
  percent_timestamp2s = str(round(j/len(diff_timestamp2s)*100,2)) + '%'               # 统计发出信号帧时间差分布
  Max_diff_timestamp2s = round(max(diff_timestamp2s),2)
  Min_diff_timestamp2s = round(min(diff_timestamp2s),2)
  
  print('接受与转发信号帧时间差分布属于30-66ms占比:',percent_timestamps,percent_timestamp2s)


  fig, axes = plt.subplots(2, 1, figsize=(15,15))
  axes[0].scatter(range(len(diff_timestamps)), diff_timestamps, s=1, color='red', label='receving_perc_diff')
  axes[1].scatter(range(len(diff_timestamp2s)), diff_timestamp2s, s=1, color='blue',label='sending_perc_diff')
  fig.text(0.45, 0.99, save_pic_name.split(".")[0], fontsize=20, va='center')

  header_str = 'diff_header_timestamps(ms)' + '\n' + 'percent[30,66]:' + percent_timestamps + '\n' + 'Max:' + str(Max_diff_timestamps) + ' Min:' + str(Min_diff_timestamps)
  send_str = 'diff_sending_timestamps(ms)' + '\n' + 'percent[30,66]:' + percent_timestamp2s + '\n' + 'Max:' + str(Max_diff_timestamp2s) + ' Min:' + str(Min_diff_timestamp2s)
  fig.text(0.01, 6.3 / 7.0, header_str , fontsize=12, va='center')
  fig.text(0.01, 3.4 / 7.0, send_str , fontsize=12, va='center')
  
  str_widthline = 'percent:|LCO|+|RC0|∈[3.0,4.5]:' + percent_widthline + '  (only if both LCO and RCO exist)'
  str_width2line = 'percent:|LLC0|+|RRC0|∈[9.0,13.5]:' + percent_width2line + '  (only if both LLCO and RRCO exist)'
  fig.text(0.01,0.98,str_widthline + '\n' + str_width2line,fontsize=12,va='center')
  fig.text(0.5, 0.07, 'frame', fontsize=12, va='center')
  plt.savefig(save_pic_name,bbox_inches='tight')
  plt.cla()



def getValidValue(timestamps, coeffs):
  valid_timestamps = []
  valid_coeffs = []
  for i in range(0, len(timestamps), 1):
    valid_flag = False
    for j in range(7):
      if coeffs[i][j] != 0.0:
        valid_flag = True
        break
    if valid_flag:
      valid_timestamps.append(timestamps[i])
      valid_coeffs.append(coeffs[i])

  return valid_timestamps, valid_coeffs


def getDiffValue(timestamps, coeffs):
  diff_timestamps = []
  diff_coeffs = []
  for i in range(0, len(timestamps)-1, 1):

    for j in range(6):
      if coeffs[i][j] != 0.0 and coeffs[i+1][j] != 0.0 :
        coeffs[i][6] = coeffs[i][5] - coeffs[i][4]
        coeffs[i][j] = coeffs[i+1][j]-coeffs[i][j]
      
    diff_timestamps.append(timestamps[i])
    diff_coeffs.append(coeffs[i])
  
  return diff_timestamps, diff_coeffs

def find_nearest(list_timestamp,start_time,end_time):
    array = np.array(list_timestamp)  
    idx = np.searchsorted(array, start_time, side="left")                                                 # 为了方便，如果开始时间戳处于两个数之间直接取小的。
    # if idx > 0 and (idx == len(array) or abs(start_time - array[idx-1]) < abs(start_time - array[idx])):
    #     idx = idx-1
    
    idx2 = np.searchsorted(array, end_time, side="left") + 1                                             # 为了方便，如果结束时间戳处于两个数之间直接取大的。
    # if idx2 > 0 and (idx2 == len(array) or abs(end_time - array[idx2-1]) < abs(end_time - array[idx2])):
    #     idx2 = idx2-1  

    return idx, idx2

def process(perc_file):
  perc_timestamp = []
  perc_timestamp2 =[]
  perc_line_0 = []
  perc_line_1 = []
  perc_line_2 = []
  perc_line_3 = []
  perc_edge_0 = []
  perc_edge_1 = []
  with open(perc_file, "rb") as f:
    lines = f.readlines()
    widthlines = []
    width2lines = []

    list_timestamps =[]
    for i in range(1,len(lines)):
      line = lines[i]
      coeffs = line.decode().strip().split(",")
      list_timestamps.append(float(coeffs[0]))

    start_time1 = int(str(start_time).replace('.','') + '000')                               # 这个文件下的时间戳不是以秒为单位的，需要改动
    end_time1 = int(str(end_time).replace('.','') + '000')
    print('相机参数起止时间戳：',start_time1,end_time1)

    start_idx,end_idx = find_nearest(list_timestamps, start_time1, end_time1)
    print('相机参数起始行index:',start_idx, end_idx)

    for i in range(start_idx,end_idx):
    # for i in range(1,len(lines)):
      line = lines[i]
      coeffs = line.decode().strip().split(",")
      perc_timestamp.append(float(coeffs[0]))
      perc_timestamp2.append(float(coeffs[1]))
      perc_line_0.append(getCoeffs(coeffs=coeffs, start_idx=2))
      perc_line_1.append(getCoeffs(coeffs=coeffs, start_idx=9))
      perc_line_2.append(getCoeffs(coeffs=coeffs, start_idx=16))
      perc_line_3.append(getCoeffs(coeffs=coeffs, start_idx=23))
      perc_edge_0.append(getCoeffs(coeffs=coeffs, start_idx=30))
      perc_edge_1.append(getCoeffs(coeffs=coeffs, start_idx=37))
      
      if coeffs[0] != 0 and coeffs[2] !=0 and coeffs[9] != 0:                              # 统计|LC0|+|RCO|
        widthlines.append(round((abs(float(coeffs[2]))+abs(float(coeffs[9]))),2) )                

      
      if coeffs[0] != 0 and coeffs[16] !=0 and coeffs[23] != 0:                            # 统计|LLCO|+|RRCO|
        width2lines.append(round((abs(float(coeffs[16]))+abs(float(coeffs[23]))),2))  
    # print(widthlines,width2lines)
    # print(perc_timestamp)

    j = 0
    global percent_widthline
    for each in widthlines:
      if each >= 3.00 and each <= 4.50 :
        j += 1   
    if j == 0:
      percent_widthline = '0' + '%'
    else:
      percent_widthline = str(round(j/len(widthlines)*100,2)) + '%'                           # 统计|LC0|+|RCO|的分布情况
    print('区间|LCO|+|RCO|属于3.0-4.5m占比',percent_widthline)

    j = 0
    global percent_width2line
    for each in width2lines:
      if each >= 9.00 and each <= 13.50 :
        j += 1
    if j ==0:
      percent_width2line = '0'+'%'
    else:
      percent_width2line = str(round(j/len(width2lines)*100,2)) + '%'                        # 统计|LLCO|+|RRCO|的分布情况
    print('区间|LLCO|+|RRCO|属于9.0-13.5m占比',percent_width2line)
      

  timestamps, coeffs = getValidValue(perc_timestamp, perc_line_0)
  plotLineCoeffs(timestamps, coeffs, "left_lane.png")
  timestamps, coeffs = getDiffValue(perc_timestamp, perc_line_0)
  plotDiffCoeffs(timestamps, coeffs, "diff_left_lane.png")

  timestamps, coeffs = getValidValue(perc_timestamp, perc_line_1)
  plotLineCoeffs(timestamps, coeffs, "right_lane.png")
  timestamps, coeffs = getDiffValue(perc_timestamp, perc_line_1)
  plotDiffCoeffs(timestamps, coeffs, "diff_right_lane.png")

  # timestamps, coeffs = getValidValue(perc_timestamp, perc_line_2)
  # plotLineCoeffs(timestamps, coeffs, "left_left_lane.png")
  # timestamps, coeffs = getDiffValue(perc_timestamp, perc_line_2)
  # plotDiffCoeffs(timestamps, coeffs, "diff_left__left_lane.png")

  # timestamps, coeffs = getValidValue(perc_timestamp, perc_line_3)
  # plotLineCoeffs(timestamps, coeffs, "right_right_lane.png")
  # timestamps, coeffs = getDiffValue(perc_timestamp, perc_line_3)
  # plotDiffCoeffs(timestamps, coeffs, "diff_right_right_lane.png")

  # timestamps, coeffs = getValidValue(perc_timestamp, perc_edge_0)
  # plotLineCoeffs(timestamps, coeffs, "left_edge.png")
  # timestamps, coeffs = getDiffValue(perc_timestamp, perc_edge_0)
  # plotDiffCoeffs(timestamps, coeffs, "diff_left_edge.png")

  # timestamps, coeffs = getValidValue(perc_timestamp, perc_edge_1)
  # plotLineCoeffs(timestamps, coeffs, "right_edge.png")
  # timestamps, coeffs = getDiffValue(perc_timestamp, perc_edge_1)
  # plotDiffCoeffs(timestamps, coeffs, "diff_right_edge.png") 

  plotTimeStampDiff(perc_timestamp, perc_timestamp2, "diff_timestamps")
  
  # print(perc_timestamp)

def imuvcuProcess(file1,file2):
  IMU_timestamps = []
  diff_imu_time = []
  VCU_timestamps = []
  diff_vcu_time = []
  GPS_timestamps = []
  diff_gps_time = []
  CAMERA_timestamps = []
  diff_camera_time = []
  with open(file1, "rb") as f:
    lines = f.readlines() 
    for line in lines:
      if 'IMU' in str(line):
        coeffs = line.decode().strip().split(",")
        if len(coeffs) > 4 :                                                # 去除掉最后一行输出title缺没有数据的情况（有待简化）
          IMU_timestamps.append(round(float((coeffs[4])),3))
      if 'VCU' in str(line):
        coeffs = coeffs = line.decode().strip().split(",")
        if len(coeffs) > 4 :
          VCU_timestamps.append(float(coeffs[4]))
      if 'GPS' in str(line):
        coeffs = coeffs = line.decode().strip().split(",")
        if len(coeffs) > 4 :
          GPS_timestamps.append(float(coeffs[4]))
  with open(file2, "rb") as f:
    lines = f.readlines() 
    for line in lines:
      coeffs = line.decode().strip().split(",")
      if len(coeffs) > 4 :                                                # 去除掉最后一行输出title缺没有数据的情况（有待简化）
        CAMERA_timestamps.append(float(coeffs[4]))  

  start_imu, end_imu = find_nearest(IMU_timestamps, start_time, end_time)
  start_vcu, end_vcu = find_nearest(VCU_timestamps, start_time, end_time)
  start_gps, end_gps = find_nearest(GPS_timestamps, start_time, end_time)
  start_camera, end_camera = find_nearest(CAMERA_timestamps, start_time, end_time)

  for i in range(start_imu+1, end_imu, 1):
    diff_imu_time.append(IMU_timestamps[i]*1000 - IMU_timestamps[i-1]*1000)
  for i in range(start_vcu+1, end_vcu, 1):
    diff_vcu_time.append(VCU_timestamps[i]*1000 - VCU_timestamps[i-1]*1000)
  for i in range(start_gps+1, end_gps, 1):
    diff_gps_time.append(GPS_timestamps[i]*1000 - GPS_timestamps[i-1]*1000)
  for i in range(start_camera+1,end_camera):
    diff_camera_time.append(CAMERA_timestamps[i]*1000 - CAMERA_timestamps[i-1]*1000)
  #print(diff_imu_time)
  
  fig, axes = plt.subplots(4, 1, sharex=True, sharey=False, figsize=(15,15))
  axes[0].scatter(IMU_timestamps[start_imu:end_imu-1], diff_imu_time, s=1, color='red', label='IMU_diff(ms)')
  axes[1].scatter(VCU_timestamps[start_vcu:end_vcu-1], diff_vcu_time, s=1, color='red', label='VCU_diff(ms)')
  axes[2].scatter(GPS_timestamps[start_gps:end_gps-1], diff_gps_time, s=1, color='red', label='GPS_diff(ms)')
  axes[3].scatter(CAMERA_timestamps[start_camera:end_camera-1], diff_camera_time, s=1, color='red', label='Camera_diff(ms)')

# 统计传感器有效占比
  i = 0
  for each in diff_imu_time:
    if each >= 9 and each <= 11:
      i = i+1
  percent_IMU = str(round((i/len(diff_imu_time))*100,2)) + '%'
  i = 0
  for each in diff_vcu_time:
    if each >= 18 and each <= 22:
      i = i+1
  percent_VCU = str(round((i/len(diff_vcu_time))*100,2)) + '%'
  i = 0
  for each in diff_gps_time:
    if each >= 90 and each <= 110:
      i = i+1
  percent_GPS = str(round((i/len(diff_gps_time))*100,2)) + '%'
  i = 0
  for each in diff_camera_time:
    if each >= 30 and each <= 66:
      i = i+1
  percent_Camera = str((i/len(diff_camera_time))*100) + '%'

  str_imu = 'IMU_diff(ms)' + '\n' +'percent[9,11]: ' + percent_IMU  + '\n' + 'MAX: ' + str(max(diff_imu_time)) + ' MIN: ' + str(min(diff_imu_time))
  str_vcu = 'VCU_diff(ms)' + '\n' +'percent[18,22]: ' + percent_VCU  + '\n' + 'MAX: ' + str(max(diff_vcu_time)) + ' MIN: ' + str(min(diff_vcu_time))
  str_gps= 'GPS_diff(ms)' + '\n' +'percent[90,110]: ' + percent_GPS  + '\n' + 'MAX: ' + str(max(diff_gps_time)) + ' MIN: ' + str(min(diff_gps_time))
  str_camera = 'Camera_diff(ms)' + '\n' +'percent[18,22]: ' + percent_Camera  + '\n' + 'MAX: ' + str(max(diff_camera_time)) + ' MIN: ' + str(min(diff_camera_time))

  fig.text(0,0.9,str_imu, fontsize=12, va='center')
  fig.text(0,0.7,str_vcu, fontsize=12, va='center')
  fig.text(0,0.5,str_gps, fontsize=12, va='center')
  fig.text(0,0.3,str_camera, fontsize = 12, va='center')
  fig.text(0.4, 0.99, 'ImuVcuGpsCamera_diff', fontsize=20, va='center')

  plt.savefig('ImuVcuGpsCamera_diff',bbox_inches='tight')
  plt.cla()

def read_MSG_POS_V17(file,start_time,end_time):
  with open(file, "rb") as f:
    lines = f.readlines()
    coeff = []
    timestamp = []
    fusion_lon = []
    fusion_lat = []
    heading = []
    mmstatus = []


    list_timestamps =[]
    for i in range(2,len(lines)):
      line = lines[i]
      coeffs = line.decode().strip().split(",")
      list_timestamps.append(round(float(coeffs[4]), 4))

    if start_time == -1 : #默认加载全部
        for i in range(1,len(lines)):
          line = lines[i]
          
          coeffs = line.decode().strip().split(",")
          if len(coeffs) == 18 and coeffs[4] !='0.000':
            coeff.append([round(float(coeffs[4]), 3),  #timestamp
                    round(float(coeffs[13]), 3)]) #heading
            timestamp.append(round(float(coeffs[4]), 4))
            fusion_lon.append(round(float(coeffs[6]), 8))
            fusion_lat.append(round(float(coeffs[5]), 8))
            heading.append(round(float(coeffs[13]), 5))
            mmstatus.append(round(float(coeffs[14]), 1))
    else :
      #start_time1 = int(str(start_time).replace('.','') + '000')                               # 这个文件下的时间戳不是以秒为单位的，需要改动
      #end_time1 = int(str(end_time).replace('.','') + '000')

      start_idx,end_idx = find_nearest(list_timestamps, start_time, end_time)
      #print(list_timestamps)
      
      for i in range(start_idx,end_idx):
        line = lines[i]
        coeffs = line.decode().strip().split(",")
        if len(coeffs) == 18:
          coeff.append([round(float(coeffs[4]), 3),  #timestamp
                    round(float(coeffs[13]), 3)]) #heading
          timestamp.append(round(float(coeffs[4]), 4))
          fusion_lon.append(round(float(coeffs[6]), 8))
          fusion_lat.append(round(float(coeffs[5]), 8))
          heading.append(round(float(coeffs[13]), 5))
          mmstatus.append(round(float(coeffs[14]), 1))
  return coeff,timestamp,fusion_lon,fusion_lat,heading,mmstatus

def read_INS(file,start_time,end_time):
  with open(file, "rb") as f:
    lines = f.readlines()
    coeff = []
    timestamp = []
    lon = []
    lat = []
    heading = []


    list_timestamps =[]
    for i in range(2,len(lines)):
      line = lines[i]
      coeffs = line.decode().strip().split(",")
      list_timestamps.append(round(float(coeffs[0])/1000.0,3))

    if start_time == -1 : #默认加载全部
        for i in range(2,len(lines)):
          line = lines[i]
          
          coeffs = line.decode().strip().split(",")
          # coeff.append([round(float(coeffs[4]), 3),  #timestamp
          #         round(float(coeffs[13]), 3)]) #heading
          timestamp.append(round(float(coeffs[0])/1000.0, 3))
          lon.append(round(float(coeffs[8]), 8))
          lat.append(round(float(coeffs[9]), 8))
          heading.append(round(float(coeffs[7]), 5))
    else :
      # start_time1 = int(str(start_time).replace('.','') + '000')                               # 这个文件下的时间戳不是以秒为单位的，需要改动
      # end_time2 = int(str(end_time).replace('.','') + '000')
      # print(list_timestamps)

      start_idx,end_idx = find_nearest(list_timestamps, start_time, end_time)
      print('Ins轨迹区间起始行index:',start_idx, end_idx)
      
      for i in range(start_idx,end_idx):
        line = lines[i]
        coeffs = line.decode().strip().split(",")
        #if len(coeffs) == 18:
        timestamp.append(round(float(coeffs[0])/1000.0, 3))
        lon.append(round(float(coeffs[8]), 8))
        lat.append(round(float(coeffs[9]), 8))
        heading.append(round(float(coeffs[7]), 5))
  return coeff,timestamp,lon,lat,heading

def process_zht(ZHT_POS_FILE,INS_FILE):
  pos_coeff,pos_timestamp,fusion_lon,fusion_lat,pos_heading,mmstatus = read_MSG_POS_V17(ZHT_POS_FILE,start_time,end_time)
  ins_coeff,ins_timestamp,ins_lon,ins_lat,ins_heading =read_INS(INS_FILE,start_time,end_time)
  ##########################
  #ins and pos heading
  save_pic_name = 'pos_ins_heading.png'
  fig = plt.figure(figsize=(15,15))

  scatter1 = plt.scatter(np.array(ins_timestamp), np.array(ins_heading), s=1, c='r',label='ins_heading')
  scatter2 = plt.scatter(np.array(pos_timestamp), np.array(pos_heading), s=1, c='y',label='pos_heading')
  plt.legend(*scatter1.legend_elements()[0],labels=["ins_heading","ZHT_heading"])
  fig.text(0.4, 0.99, 'ins/ZHT_heading', fontsize=20, va='center')
  plt.savefig(save_pic_name,bbox_inches='tight')

  #航向角帧间的差值
  save_pic_name = "INS_ZHT_diff_heading.png"
  fig = plt.figure(figsize=(15,15))
  # ax1 = plt.subplot(3, 1, 1)
  ZHT_diff_heading = []
  ins_diff_heading = []

  for i in range(0, len(ins_heading)-1, 1):
    heading1 = round(float(ins_heading[i]),5)
    heading2 = round(float(ins_heading[i+1]),5)
    delta_heading = heading2 -heading1
    if delta_heading >=-10 and delta_heading <=10:
      ins_diff_heading.append(heading2 - heading1)

  for i in range(0, len(pos_heading)-1, 1):
    heading1 = round(float(pos_heading[i]),5)
    heading2 = round(float(pos_heading[i+1]),5)
    delta_heading = heading2 -heading1
    if delta_heading >=-10 and delta_heading <=10:
      ZHT_diff_heading.append(heading2 - heading1)
  # scatter3 = plt.scatter(np.arange(len(ins_diff_heading)), ins_diff_heading, s=1, color='blue', label='perc')
  scatter4 = plt.scatter(np.arange(len(ZHT_diff_heading)), ZHT_diff_heading, s=1, color='red', label='perc')
  plt.legend(*scatter4.legend_elements()[0],labels=["ZHT_diff_heading"])
  fig.text(0.4, 0.99, 'ins/ZHT_heading_diff', fontsize=20, va='center')
  plt.savefig(save_pic_name,bbox_inches='tight')

  #融合定位轨迹与ins轨迹
  utm_ins_lat = []
  utm_ins_lon = []
  utm_fusion_lat =[]
  utm_fusion_lon = []
  transformer = Transformer.from_crs("epsg:4326", "epsg:32649") 
  # print(ins_lat,ins_lon)
  for i in range(len(ins_lat)):
    x, y = transformer.transform(ins_lat[i], ins_lon[i])
    utm_ins_lat.append(x)
    utm_ins_lon.append(y)

  for i in range(len(fusion_lat)):

    x, y = transformer.transform(fusion_lat[i],fusion_lon[i])
    utm_fusion_lat.append(x)
    utm_fusion_lon.append(y)
  # print(utm_fusion_lat)
  
  utm_ins_lat[:] = [ x - utm_ins_lat[1] for x in utm_ins_lat]
  utm_ins_lon[:] = [ x - utm_ins_lon[1] for x in utm_ins_lon]
  utm_fusion_lat[:] = [ x - utm_fusion_lat[1] for x in utm_fusion_lat]
  utm_fusion_lon[:] = [ x - utm_fusion_lon[1] for x in utm_fusion_lon]
  
  fig = plt.figure(figsize=(15,15))
  plt.scatter(utm_ins_lon, utm_ins_lat, s=0.1, color='red', label='perc')
  plt.scatter(utm_fusion_lon, utm_fusion_lat,  s=1, color='blue', label='perc')
  plt.legend(*scatter1.legend_elements()[0],labels=["ins","ZHT_fusion"])
  fig.text(0.4, 0.99, 'ins/fusion_track', fontsize=20, va='center')
  plt.savefig('ins_fusion_track', bbox_inches='tight')
  

base_time = 1679622625.520 # 单位s
start_time = str('%.3f'%(float(base_time - 5.0)))
end_time   = str('%.3f'%(float(base_time + 5.0)))
print('区间起始时间:',start_time,end_time)
#start_time,end_time = (float(1678094422.016),float(1678094427.016))       # 输入的时间戳格式为 1668654666.420,这里要保留小数后三位（0要保留）
sigma = 0.02                                                               # sigma 输入小数即可
 
if __name__=="__main__":  
  base_dir = "/media/alex/0b30339f-2655-ed45-a5fe-dff30aa706a8/融合定位评测数据_ZHT/路线2/0324/localization_log"
  loc_perc_data = base_dir + "/perc_data_2023_3_24_9_45_44.txt"
  loc_ins_data  = base_dir + "/ins_data_2023_3_24_9_45_44.txt"

  base_dir2 = "/media/alex/0b30339f-2655-ed45-a5fe-dff30aa706a8/融合定位评测数据_ZHT/路线2/0324/log/POS20230324_094540"
  pos_Middle_DataIN = base_dir2 + "/Middle_DataIN.log"
  pos_ADAS = base_dir2 + "/MSG_ADAS_V10.log"
  pos_MSG_POS_V17 = base_dir2 + "/MSG_POS_V17.log"
  
  process(loc_perc_data)
  imuvcuProcess(pos_Middle_DataIN,pos_ADAS)
  process_zht(pos_MSG_POS_V17,loc_ins_data)



# 注意：perc_data里的时间戳为16位，unix标准时间戳为10位，单位是秒