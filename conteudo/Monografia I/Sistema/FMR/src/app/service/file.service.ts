import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders, HttpParams, HttpRequest } from '@angular/common/http';
import { UrlService } from './default/url.service';

@Injectable({
  providedIn: 'root'
})
export class FileService {

  private baseUrl: string = this._url.baseUrl() + "/upload";
  
  constructor(private _http : HttpClient, private _url : UrlService) { }

  upload(file : File) {
    const uploadData = new FormData();
    uploadData.append('file', file, file.name);

    const req = new HttpRequest('POST', this.baseUrl, uploadData)
    return this._http.post(this.baseUrl, uploadData);
    //return this._http.request(req);
  }

  get(file: string) {
    return this._http.get(file);
    //return this._http.get(this.baseUrl + "/" + file);
  }
}
