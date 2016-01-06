package com.tigerknows.config;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Properties;
import java.util.Set;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
/*
 * 配置文件的放的位置是“/opt/permission”
 */
public class LoadProperty {
	private static Log log = LogFactory.getLog(LoadProperty.class);
	
	public static String getKeyData(String tmpKey,String tmpProPath){
		if((tmpKey == null) || (tmpProPath == null))
			return null;
		
		Map<String,String> tmpStore=getFileData(tmpProPath);
		if(tmpStore ==null)
			return null;
		return tmpStore.get(tmpKey);
	}
	
	//如果读取文件失败，该函数返回null
	public static Map<String, String> getFileData(String tmpProPath) {
		log.info("读取文件：");
		log.info(tmpProPath);
		Map<String, String> tmpStore = new HashMap<String, String>();
		Properties prop = new Properties();
		try {
			InputStream in=new FileInputStream(new File(tmpProPath));
			prop.load(new InputStreamReader(in,"UTF-8")); /// 加载属性列表
			Iterator<String> it = prop.stringPropertyNames().iterator();
			while (it.hasNext()) {
				String key = it.next();
				//System.out.println(key + ":" + prop.getProperty(key));
				tmpStore.put(key, prop.getProperty(key));
			}
			in.close();
		} catch (Exception e) {
			log.error("读取下面文件失败：");
			log.error(tmpProPath);
			return null;
		}
		return tmpStore;
	}

	public static boolean putFileData(String tmpProPath, Map<String, String> tmpMap) {
		Properties prop = new Properties();
		try {
			FileOutputStream oFile = new FileOutputStream(tmpProPath, true);// true表示追加打开
			Set<String> keySet = tmpMap.keySet();
			for (String tmpKeyObj : keySet)
				prop.setProperty(tmpKeyObj, tmpMap.get(tmpKeyObj));

			// prop.setProperty("phone", "10086");
			// prop.store(oFile, "The New properties file");
			oFile.close();
		} catch (Exception e) {
			return false;
		}
		return true;
	}
	public static void main(String[] args) {
		Properties prop = new Properties();
		try {
			// 读取属性文件a.properties
			InputStream in = new BufferedInputStream(new FileInputStream("./src/a.properties"));
			prop.load(in); /// 加载属性列表
			Iterator<String> it = prop.stringPropertyNames().iterator();
			while (it.hasNext()) {
				String key = it.next();
				System.out.println(key + ":" + prop.getProperty(key));
			}
			in.close();

			/// 保存属性到b.properties文件
			FileOutputStream oFile = new FileOutputStream("./src/b.properties", true);// true表示追加打开
			prop.setProperty("phone", "10086");
			prop.store(oFile, "The New properties file");
			oFile.close();
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
