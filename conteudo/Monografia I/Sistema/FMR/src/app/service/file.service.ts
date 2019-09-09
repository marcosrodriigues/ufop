import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders, HttpParams, HttpRequest } from '@angular/common/http';

@Injectable({
  providedIn: 'root'
})
export class FileService {

  private baseUrl: string = "http://localhost:8080/upload";
  
  constructor(private _http : HttpClient) { }

  upload(file : File) {
    const uploadData = new FormData();
    uploadData.append('file', file, file.name);

    const req = new HttpRequest('POST', this.baseUrl, uploadData)
    return this._http.post(this.baseUrl, uploadData);
    //return this._http.request(req);
  }

  get(file: string) {
    return this._http.get(this.baseUrl + "/" + file);
  }
}
